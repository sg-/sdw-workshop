/* FXOS8700Q sensor driver
 * Copyright (c) 2014-2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#ifndef FXOS8700Q_H
#define FXOS8700Q_H
 
#include "mbed-drivers/mbed.h"
#include "MotionSensor/MotionSensor.h"
 
// FXOS8700CQ I2C address
#define FXOS8700CQ_SLAVE_ADDR0 (0x1E<<1) // with pins SA0=0, SA1=0
#define FXOS8700CQ_SLAVE_ADDR1 (0x1D<<1) // with pins SA0=1, SA1=0
#define FXOS8700CQ_SLAVE_ADDR2 (0x1C<<1) // with pins SA0=0, SA1=1
#define FXOS8700CQ_SLAVE_ADDR3 (0x1F<<1) // with pins SA0=1, SA1=1
// FXOS8700CQ internal register addresses
#define FXOS8700Q_STATUS 0x00
#define FXOS8700Q_OUT_X_MSB 0x01
#define FXOS8700Q_OUT_Y_MSB 0x03
#define FXOS8700Q_OUT_Z_MSB 0x05
#define FXOS8700Q_M_OUT_X_MSB 0x33
#define FXOS8700Q_M_OUT_Y_MSB 0x35
#define FXOS8700Q_M_OUT_Z_MSB 0x37
#define FXOS8700Q_WHOAMI 0x0D
#define FXOS8700Q_XYZ_DATA_CFG 0x0E
#define FXOS8700Q_CTRL_REG1 0x2A
#define FXOS8700Q_M_CTRL_REG1 0x5B
#define FXOS8700Q_M_CTRL_REG2 0x5C
#define FXOS8700Q_WHOAMI_VAL 0xC7
 
 
/** FXOS8700Q accelerometer example
    @code
    ...
    @endcode
 */
 
/** FXOS8700Q driver
 */
class FXOS8700Q : public MotionSensor
{
public:
 
    /** Read a device register
        @param addr The address to read from
        @param data The data to read from it
        @param len The amount of data to read from it
        @return 0 if successful, negative number otherwise
     */
    void readRegs(uint8_t addr, uint8_t *data, uint32_t len) const;
 
    /** Read the ID from a whoAmI register
        @return The device whoAmI register contents
     */
    uint8_t whoAmI(void) const;
 
    virtual void enable(void) const;
    virtual void disable(void) const;
    virtual uint32_t sampleRate(uint32_t frequency) const;
    virtual uint32_t dataReady(void) const;
 
protected:
    I2C *_i2c;
    uint8_t _addr;
    
    /** FXOS8700Q constructor
        @param i2c a configured i2c object
        @param addr addr of the I2C peripheral as wired
     */
    FXOS8700Q(I2C &i2c, uint8_t addr);
 
    /** FXOS8700Q deconstructor
     */
    ~FXOS8700Q();
    
    void writeRegs(uint8_t *data, uint32_t len) const;
    int16_t getSensorAxis(uint8_t addr) const;
};
 
/** FXOS8700QAccelerometer interface
 */
class FXOS8700QAccelerometer : public FXOS8700Q
{
public:
 
    FXOS8700QAccelerometer(I2C &i2c, uint8_t addr) : FXOS8700Q(i2c, addr) {}
 
    virtual int16_t getX(int16_t &x) const;
    virtual int16_t getY(int16_t &y) const;
    virtual int16_t getZ(int16_t &z) const;
    virtual float getX(float &x) const;
    virtual float getY(float &y) const;
    virtual float getZ(float &z) const;
    virtual void getAxis(motion_data_counts_t &xyz) const;
    virtual void getAxis(motion_data_units_t &xyz) const;
 
};
 
/** FXOS8700QMagnetometer interface
 */
class FXOS8700QMagnetometer : public FXOS8700Q
{
public:
 
    FXOS8700QMagnetometer(I2C &i2c, uint8_t addr) : FXOS8700Q(i2c, addr) {}
 
    virtual int16_t getX(int16_t &x) const;
    virtual int16_t getY(int16_t &y) const;
    virtual int16_t getZ(int16_t &z) const;
    virtual float getX(float &x) const;
    virtual float getY(float &y) const;
    virtual float getZ(float &z) const;
    virtual void getAxis(motion_data_counts_t &xyz) const;
    virtual void getAxis(motion_data_units_t &xyz) const;
 
};
 
#endif
 