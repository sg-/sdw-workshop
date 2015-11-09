/*
 * Copyright (c) 2015 ARM Limited. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "sockets/UDPSocket.h"
#include "EthernetInterface.h"
#include "mbed-drivers/test_env.h"
#include "mbed-client/m2minterfacefactory.h"
#include "mbed-client/m2mdevice.h"
#include "mbed-client/m2minterfaceobserver.h"
#include "mbed-client/m2minterface.h"
#include "mbed-client/m2mobjectinstance.h"
#include "mbed-client/m2mresource.h"
#include "minar/minar.h"
#include "lwipv4_init.h"

#include "FXOS8700Q/FXOS8700Q.h"
#include "security.h"
#include "mbed-client-impl.h"

using namespace mbed::util;

Serial output(USBTX, USBRX);

EthernetInterface eth;
// Instantiate the class which implements
// LWM2M Client API
MbedClient mbed_client;

// Set up Hardware interrupt button.
InterruptIn unreg_button(SW3);

I2C i2c(PTE25, PTE24);
// Configured for the FRDM-K64F with onboard sensors
FXOS8700QAccelerometer acc(i2c, FXOS8700CQ_SLAVE_ADDR1);

void app_start(int /*argc*/, char* /*argv*/[]) {

    //Sets the console baud-rate
    output.baud(115200);

    // start the accelerometer and magnetometer
    acc.enable();
    motion_data_units_t acc_data;
    while (1) {
        acc.getAxis(acc_data);
        output.printf("ACC: X=%1.4ff Y=%1.4ff Z=%1.4f\r\n", acc_data.x, acc_data.y, acc_data.z);
        wait(1.0f);
    }

    // This sets up the network interface configuration which will be used
    // by LWM2M Client API to communicate with mbed Device server.
    eth.init(); //Use DHCP
    eth.connect();
    
    char *ip = eth.getIPAddress();
    if (ip) {
        output.printf("IP Address is: %s\n", ip);
    } else {
        error("Failed to aquire IP address\n");
    }

    lwipv4_socket_init();
    output.printf("IP address %s\r\n", eth.getIPAddress());

    // On press of SW3 button on K64F board, example application
    // will call unregister API towards mbed Device Server
    unreg_button.fall(&mbed_client,&MbedClient::test_unregister);

    // Create LWM2M Client API interface to manage register and unregister
    mbed_client.create_interface();

    // Create LWM2M server object specifying mbed device server
    // information.
    M2MSecurity* register_object = mbed_client.create_register_object();

    // Create LWM2M device object specifying device resources
    // as per OMA LWM2M specification.
    M2MDevice* device_object = mbed_client.create_device_object();

    // Create Generic object specifying custom resources
    M2MObject* sdw_object = mbed_client.create_sdw_object();

    // Add all the objects that you would like to register
    // into the list and pass the list for register API.
    M2MObjectList object_list;
    object_list.push_back(device_object);
    object_list.push_back(sdw_object);

    mbed_client.set_register_object(register_object);

    // Issue register command.
    FunctionPointer2<void, M2MSecurity*, M2MObjectList> fp(&mbed_client, &MbedClient::test_register);
    minar::Scheduler::postCallback(fp.bind(register_object, object_list));
    minar::Scheduler::postCallback(&mbed_client, &MbedClient::update_sdw_resource).period(minar::milliseconds(5000));
    minar::Scheduler::postCallback(&mbed_client, &MbedClient::test_update_register).period(minar::milliseconds(25000));
}
       