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
#include "test_env.h"
#include "mbed-client/m2minterfacefactory.h"
#include "mbed-client/m2mdevice.h"
#include "mbed-client/m2minterfaceobserver.h"
#include "mbed-client/m2minterface.h"
#include "mbed-client/m2mobjectinstance.h"
#include "mbed-client/m2mresource.h"
#include "minar/minar.h"
#include "security.h"
#include "mbed-client-impl.h"

#include "lwipv4_init.h"

using namespace mbed::util;

Serial output(USBTX, USBRX);

EthernetInterface eth;
// Instantiate the class which implements
// LWM2M Client API
MbedClient mbed_client;

// Set up Hardware interrupt button.
InterruptIn obs_button(SW2);
InterruptIn unreg_button(SW3);

void app_start(int /*argc*/, char* /*argv*/[]) {

    //Sets the console baud-rate
    output.baud(115200);

    // This sets up the network interface configuration which will be used
    // by LWM2M Client API to communicate with mbed Device server.
    eth.init(); //Use DHCP
    eth.connect();

    lwipv4_socket_init();
    output.printf("IP address %s\r\n", eth.getIPAddress());

    // On press of SW3 button on K64F board, example application
    // will call unregister API towards mbed Device Server
    unreg_button.fall(&mbed_client,&MbedClient::test_unregister);

    // On press of SW2 button on K64F board, example application
    // will send observation towards mbed Device Server
    obs_button.fall(&mbed_client,&MbedClient::update_resource);

    // Create LWM2M Client API interface to manage register and unregister
    mbed_client.create_interface();

    // Create LWM2M server object specifying mbed device server
    // information.
    M2MSecurity* register_object = mbed_client.create_register_object();

    // Create LWM2M device object specifying device resources
    // as per OMA LWM2M specification.
    M2MDevice* device_object = mbed_client.create_device_object();

    // Create Generic object specifying custom resources
    M2MObject* generic_object = mbed_client.create_generic_object();
    
    // Create sdw resource
    M2MObject* sdw_object = mbed_client.create_sdw_object();

    // Add all the objects that you would like to register
    // into the list and pass the list for register API.
    M2MObjectList object_list;
    object_list.push_back(device_object);
    object_list.push_back(generic_object);
    object_list.push_back(sdw_object);

    mbed_client.set_register_object(register_object);

    // Issue register command.
    FunctionPointer2<void, M2MSecurity*, M2MObjectList> fp(&mbed_client, &MbedClient::test_register);
    minar::Scheduler::postCallback(fp.bind(register_object,object_list));
    minar::Scheduler::postCallback(&mbed_client,&MbedClient::test_update_register).period(minar::milliseconds(25000));
}
       