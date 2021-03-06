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
#ifndef __MBED_CLIENT_IMPL_H__
#define __MBED_CLIENT_IMPL_H__

#include "sockets/UDPSocket.h"
#include "mbed-client/m2minterfacefactory.h"
#include "mbed-client/m2mdevice.h"
#include "mbed-client/m2minterfaceobserver.h"
#include "mbed-client/m2minterface.h"
#include "mbed-client/m2mobjectinstance.h"
#include "mbed-client/m2mresource.h"
#include "mbed-drivers/test_env.h"

// Comment out to use Authenticated IoTF
#define USE_QUICKSTART  true

// modified security.h to toggle between QuickStart and Authenticated IoTF
#include "security.h"

//Select binding mode: UDP or TCP
M2MInterface::BindingMode SOCKET_MODE = M2MInterface::UDP;

#ifdef USE_QUICKSTART
    // Select connection mode: Certificate or NoSecurity
    // QuickStart
    M2MSecurity::SecurityModeType CONN_MODE = M2MSecurity::NoSecurity;
    
    // use one of these for QuickStart
    const String &MBED_SERVER_ADDRESS = "coap://129.41.135.57:5683";      // primary
    //const String &MBED_SERVER_ADDRESS = "coap://134.168.22.97:5683";    // backup
#else
    // IoTF Bridge
    M2MSecurity::SecurityModeType CONN_MODE = M2MSecurity::Certificate;
    
    // This is address to mbed Device Connector
    const String &MBED_SERVER_ADDRESS = "coap://api.connector.mbed.com:5684";
#endif

const String &MBED_USER_NAME_DOMAIN = MBED_DOMAIN;
const String &ENDPOINT_NAME = MBED_ENDPOINT_NAME;

const String &MANUFACTURER = "Freescale";
const String &TYPE = "mbed";
const String &MODEL_NUMBER = "K64F";
const String &SERIAL_NUMBER = "12345";

const uint8_t STATIC_VALUE[] = "Static value";

extern Serial output;
extern FXOS8700QAccelerometer acc;

extern DigitalOut __led;

class MbedClient: public M2MInterfaceObserver {
public:
    MbedClient() {
        _interface = NULL;
        _bootstrapped = false;
        _error = false;
        _registered = false;
        _unregistered = false;
        _register_security = NULL;
        _value = 0;
        _sdw_object = NULL;
    }

    ~MbedClient() {
        if (_interface) {
            delete _interface;
        }
        if (_register_security) {
            delete _register_security;
        }
    }

    void trace_printer(const char* format, ...) {
        va_list argp;
        va_start(argp, format);
        output.vprintf(format, argp);
        va_end(argp);
    }

    void create_interface() {
        // Creates M2MInterface using which endpoint can
        // setup its name, resource type, life time, connection mode,
        // Currently only LwIPv4 is supported.

    	// Randomizing listening port for Certificate mode connectivity
    	srand(time(NULL));
    	uint16_t port = rand() % 65535 + 12345;

        _interface = M2MInterfaceFactory::create_interface(*this,
                                                  ENDPOINT_NAME,
                                                  "mbed",
                                                  3600,
                                                  port,
                                                  MBED_USER_NAME_DOMAIN,
                                                  SOCKET_MODE,
                                                  M2MInterface::LwIP_IPv4,
                                                  "");
    }

    bool register_successful() {
        return _registered;
    }

    bool unregister_successful() {
        return _unregistered;
    }

    M2MSecurity* create_register_object() {
        // Creates register server object with mbed device server address and other parameters
        // required for client to connect to mbed device server.
        M2MSecurity *security = M2MInterfaceFactory::create_security(M2MSecurity::M2MServer);
        if (security && CONN_MODE == M2MSecurity::Certificate) {
            security->set_resource_value(M2MSecurity::M2MServerUri, MBED_SERVER_ADDRESS);
            security->set_resource_value(M2MSecurity::SecurityMode, M2MSecurity::Certificate);
            security->set_resource_value(M2MSecurity::ServerPublicKey,SERVER_CERT,sizeof(SERVER_CERT));
            security->set_resource_value(M2MSecurity::PublicKey,CERT,sizeof(CERT));
            security->set_resource_value(M2MSecurity::Secretkey,KEY,sizeof(KEY));
        }
        else{
            security->set_resource_value(M2MSecurity::M2MServerUri, MBED_SERVER_ADDRESS);
            security->set_resource_value(M2MSecurity::SecurityMode, M2MSecurity::NoSecurity);
        }
        return security;
    }

    M2MDevice* create_device_object() {
        // Creates device object which contains mandatory resources linked with
        // device endpoint.
        M2MDevice *device = M2MInterfaceFactory::create_device();
        if (device) {
            device->create_resource(M2MDevice::Manufacturer,MANUFACTURER);
            device->create_resource(M2MDevice::DeviceType,TYPE);
            device->create_resource(M2MDevice::ModelNumber,MODEL_NUMBER);
            device->create_resource(M2MDevice::SerialNumber,SERIAL_NUMBER);
        }
        return device;
    }
    
    M2MObject* create_led_object() {
        _sdw_led_object = M2MInterfaceFactory::create_object("311");
        
        if (_sdw_led_object) {
            M2MObjectInstance* inst = _sdw_led_object->create_object_instance();
            if (inst) {
                M2MResource* res = inst->create_dynamic_resource("5850",
                                                                 "LED",
                                                                 M2MResourceInstance::STRING,
                                                                 false);
                if (res) {
                    char buffer[10] = "";
                    memset(buffer,0,10);
                    strcpy(buffer,"0");
                    if (__led == 1) strcpy(buffer,"1");
                    
                    // set the value of the LED 
                    res->set_operation(M2MBase::GET_PUT_ALLOWED);   // we allow GET and PUT of the LED
                    res->set_value((const uint8_t*)buffer,
                                   (const uint32_t)strlen(buffer));
                    trace_printer("%s\n", buffer);
                } else {
                    trace_printer("%s:%d - Failed to create LED Resource\n", __FILE__, __LINE__);
                }
            }
        }
        return _sdw_led_object;
    }

    M2MObject* create_sdw_object() {
        _sdw_object = M2MInterfaceFactory::create_object("777");
        
        if (_sdw_object) {
            M2MObjectInstance* inst = _sdw_object->create_object_instance();
            if (inst) {
                M2MResource* res = inst->create_dynamic_resource("7777",
                                                                 "FXOS8700Q",
                                                                 M2MResourceInstance::STRING,
                                                                 true);
                if (res) {
                    char buffer[128] = "";
                    // fill the value of the acceleromter
                    sprintf(buffer,"{\"accelX\":%1.1f, \"accelY\":%1.1f, \"accelZ\":%1.1f}", 0.0f, 0.0f ,0.0f);
                    // set the value of the accelerometer data
                    res->set_operation(M2MBase::GET_ALLOWED);
                    res->set_value((const uint8_t*)buffer,
                                   (const uint32_t)strlen(buffer));
                    trace_printer("%s\n", buffer);
                } else {
                    trace_printer("%s:%d - Failed to create M2MResource\n", __FILE__, __LINE__);
                }
            }
        }
        return _sdw_object;
    }

    void update_sdw_resource() {
        if (_sdw_object) {
            M2MObjectInstance* inst = _sdw_object->object_instance();
            if (inst) {
                M2MResource* res = inst->resource("7777");
                if (res) {
                    char buffer[128] = "";
                    motion_data_units_t data;
                    acc.getAxis(data);
                    // fill the value of the acceleromter
                    sprintf(buffer,"{\"accelX\":%1.1f, \"accelY\":%1.1f, \"accelZ\":%1.1f}", data.x, data.y ,data.z);                
                    // set the value of the accelerometer data
                    res->set_value((const uint8_t*)buffer,
                                   (const uint32_t)strlen(buffer));
                    trace_printer("%s\n", buffer);
                } else {
                    trace_printer("%s:%d - Failed to get M2MResource\n", __FILE__, __LINE__);
                }
            }
        }
    }

    void test_register(M2MSecurity *register_object, M2MObjectList object_list) {
        if (_interface) {
            // Register function
            _interface->register_object(register_object, object_list);
        }
    }

    void test_unregister() {
        if (_interface) {
            // Unregister function
            _interface->unregister_object(NULL);
        }
    }

    //Callback from mbed client stack when the bootstrap
    // is successful, it returns the mbed Device Server object
    // which will be used for registering the resources to
    // mbed Device server.
    void bootstrap_done(M2MSecurity *server_object) {
        if (server_object) {
            _bootstrapped = true;
            _error = false;
            trace_printer("\nBootstrapped\n");
        }
    }

    //Callback from mbed client stack when the registration
    // is successful, it returns the mbed Device Server object
    // to which the resources are registered and registered objects.
    void object_registered(M2MSecurity */*security_object*/, const M2MServer &/*server_object*/) {
        _registered = true;
        _unregistered = false;
        trace_printer("\nRegistered\n");
    }

    //Callback from mbed client stack when the unregistration
    // is successful, it returns the mbed Device Server object
    // to which the resources were unregistered.
    void object_unregistered(M2MSecurity */*server_object*/) {
        _unregistered = true;
        _registered = false;
        notify_completion(_unregistered);
        minar::Scheduler::stop();
        trace_printer("\nUnregistered\n");
    }

    void registration_updated(M2MSecurity */*security_object*/, const M2MServer & /*server_object*/) {
    }

    //Callback from mbed client stack if any error is encountered
    // during any of the LWM2M operations. Error type is passed in
    // the callback.
    void error(M2MInterface::Error error) {
        _error = true;
        switch(error) {
            case M2MInterface::AlreadyExists:
                trace_printer("[ERROR:] M2MInterface::AlreadyExists\n");
                break;
            case M2MInterface::BootstrapFailed:
                trace_printer("[ERROR:] M2MInterface::BootstrapFailed\n");
                break;
            case M2MInterface::InvalidParameters:
                trace_printer("[ERROR:] M2MInterface::InvalidParameters\n");
                break;
            case M2MInterface::NotRegistered:
                trace_printer("[ERROR:] M2MInterface::NotRegistered\n");
                break;
            case M2MInterface::Timeout:
                trace_printer("[ERROR:] M2MInterface::Timeout\n");
                break;
            case M2MInterface::NetworkError:
                trace_printer("[ERROR:] M2MInterface::NetworkError\n");
                break;
            case M2MInterface::ResponseParseFailed:
                trace_printer("[ERROR:] M2MInterface::ResponseParseFailed\n");
                break;
            case M2MInterface::UnknownError:
                trace_printer("[ERROR:] M2MInterface::UnknownError\n");
                break;
            case M2MInterface::MemoryFail:
                trace_printer("[ERROR:] M2MInterface::MemoryFail\n");
                break;
            case M2MInterface::NotAllowed:
                trace_printer("[ERROR:] M2MInterface::NotAllowed\n");
                break;
            default:
                break;
        }
    }

    //Callback from mbed client stack if any value has changed
    // during PUT operation. Object and its type is passed in
    // the callback.
    void value_updated(M2MBase *base, M2MBase::BaseType type) {
        output.printf("\nUpdate Object name %s and Type %d\n", base->name().c_str(), type);
        
        // only the LED supports PUT so lets see if its this instance...
        M2MObjectInstance* inst = _sdw_led_object->object_instance();
        if (inst) {
            // should be the /311/0/5850 resource... check for it...
            M2MResource* res = inst->resource("5850");
            if (res != NULL && base == res) {
                // extract the LED value...
                char *new_led_value = (char *)(res->value());
                
                // DEBUG
                printf("\nLight Switch Resource Changed! [%s]\n",new_led_value);
                
                // Update the LED
                if (strcmp(new_led_value,"1") == 0) {
                    __led = 0;
                }
                else {
                    __led = 1;
                }
            }
        }
    }

    void test_update_register() {
        if (_registered) {
            _interface->update_registration(_register_security, 3600);
        }
    }

   void set_register_object(M2MSecurity *register_object) {
        if (_register_security == NULL) {
            _register_security = register_object;
        }
    }

private:

    M2MInterface    	*_interface;
    M2MSecurity         *_register_security;
    M2MObject           *_sdw_object;
    M2MObject           *_sdw_led_object;
    volatile bool       _bootstrapped;
    volatile bool       _error;
    volatile bool       _registered;
    volatile bool       _unregistered;
    int                 _value;
};

#endif
