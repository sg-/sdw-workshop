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
#ifndef M2MFIRMWARE_H
#define M2MFIRMWARE_H

#include "mbed-client/m2mobject.h"

// FORWARD DECLARATION
class M2MResource;
class M2MResourceInstance;

/**
 *  @brief M2MFirmware.
 *  This class represents the Firmware Object model of LWM2M framework.
 *  This class will provide interface for handling the firmware object
 *  and all its corresponding resources.There can be only one instance
 *  of Firmware Object.
 */
class  M2MFirmware : public M2MObject {

friend class M2MInterfaceFactory;

public:

     /**
      * @brief Enum defining all the resources associated with
      * Firmware Object in LWM2M framework.
      */
    typedef enum {
        Package,
        PackageUri,
        Update,
        State,
        UpdateSupportedObjects,
        UpdateResult,
        PackageName,
        PackageVersion
    } FirmwareResource;

    /**
     * @brief Enum defining state of firmware update.
     */
    typedef enum {
       Idle = 1,
       Downloading,
       Downloaded
    } UpdateState;

    /**
     * @brief Enum defining result of firmware update.
     */
    typedef enum {
       Default = 0,
       SuccessfullyUpdated,
       NotEnoughSpace,
       OutOfMemory,
       ConnectionLost,
       CRCCheckFailure,
       UnsupportedPackageType,
       InvalidURI
    } ResultOfUpdate;

private:

    /**
     * Constructor
     */
    M2MFirmware();

    // Prevents the use of assignment operator.
    M2MFirmware& operator=( const M2MFirmware& /*other*/ );

    // Prevents the use of copy constructor
    M2MFirmware( const M2MFirmware& /*other*/ );

    /**
     * Destructor
     */
    virtual ~M2MFirmware();

    static M2MFirmware* get_instance();

public:

    /**
     * @brief Deletes the M2MFirmware instance.
     */
    static void delete_instance();

    /**
     * @brief Creates a new resource for given resource enum.
     * @param resource, List of resource names which can be created using this function are
     * 'PackageUri', 'PackageName','PackageVersion'.
     * @param value, Value to be set on the resource, in String format.
     * @return M2MResource if created successfully else NULL.
     */
    M2MResource* create_resource(FirmwareResource resource, const String &value);

    /**
     * @brief Creates a new resource for given resource enum.
     * @param resource, List of resource names which can be created using this function are
     * 'State','UpdateSupportedObjects','UpdateResult'.
     * @param value, Value to be set on the resource, in Integer format.
     * @return M2MResource if created successfully else NULL.
     */
    M2MResource* create_resource(FirmwareResource resource, int64_t value);

    /**
     * @brief Deletes the resource with the given resource enum,
     * it cannot not delete the mandatory resources.
     * @param resource, Name of the resource to be deleted.
     * @return True if deleted else false.
     */
    bool delete_resource(FirmwareResource resource);

    /**
     * @brief Sets the value of the given resource enum.
     * @param resource, List of resource name for which value can be set
     * using this function are
     * 'Package', 'PackageUri', 'PackageName','PackageVersion'.
     * @param value, Value to be set on the key, in String format.     
     * @return True if successfully set else false.
     */
    bool set_resource_value(FirmwareResource resource,
                            const String &value);

    /**
     * @brief Sets the value of the given resource enum.
     * @param resource, List of resource name for which value can be set
     * using this function are
     * 'State','UpdateSupportedObjects','UpdateResult'.
     * @param value, Value to be set on the key, in Integer format
     * @return True if successfully set else false.
     */
    bool set_resource_value(FirmwareResource resource,
                            int64_t value);

    /**
     * @brief Sets the value of the given resource enum.
     * @param resource, List of resource name for which value can be set
     * using this function are
     * 'Package'.
     * @param value, Value to be set on the key, in uint8_t format.
     * @param size, size of the buffer value to be set on the key.
     * @return True if successfully set else false.
     */
    bool set_resource_value(FirmwareResource resource,
                            const uint8_t *value,
                            const uint32_t length);

    /**
     * @brief Returns the value of the given resource enum, in String.
     * @param resource, List of resource names which can return value using this function are
     * 'PackageUri', 'PackageName','PackageVersion'.
     * @return Value associated with that key, if key is not valid it returns NULL.
     */
    String resource_value_string(FirmwareResource resource) const;

    /**
     * @brief Returns the value of the given resource key name, in Integer.
     * @param resource, List of resource names which can return value using this function are
     * 'State','UpdateSupportedObjects','UpdateResult'.     
     * @return Value associated with that key, if key is not valid it returns -1.
     */
    int64_t resource_value_int(FirmwareResource resource) const;

    /**
     * @brief Populates the data buffer and returns the size of the buffer.
     * @param resource, List of resource names which can return value using this function are
     * 'Package'.
     * @param [OUT] data, Data buffer which will contain the value.
     * @return Size of the buffer populated .
     */
    uint32_t resource_value_buffer(FirmwareResource resource,
                                   uint8_t *&data) const;

    /**
     * @brief Returns if the resource instance with given resource enum exists or not.
     * @param resource, resource enum.
     * @return True if at least one instance exists else false.
     */
    bool is_resource_present(FirmwareResource resource) const;

    /**
     * @brief Returns number of resources for whole firmware object.
     * @return Total number of resources belonging to firmware object.
     */
    uint16_t total_resource_count() const;

    /**
     * @brief Returns number of resources for given resource enum.
     * @param resource, resource enum.
     * @return Number of resources for a given resource enum returns 1 for
     * mandatory resources else can be 0 as well if no instance exists for an
     * optional resource.
     */
    uint16_t per_resource_count(FirmwareResource resource) const;


private:

    M2MResource* get_resource(FirmwareResource resource) const;

    String resource_name(FirmwareResource resource) const;

    void create_mandatory_resources();

    bool check_value_range(FirmwareResource resource, const int64_t value) const;

private :

    M2MObjectInstance*    _firmware_instance;     //Not owned

protected:

    static M2MFirmware*     _instance;

    friend class Test_M2MFirmware;
    friend class Test_M2MInterfaceFactory;
};


#endif // M2MFIRMWARE_H
