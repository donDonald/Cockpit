#pragma once

#include "Types.h"
#include <Wire.h>

TwoWire& _wire = Wire;

class Bus
{
public:
    Bus(uint8_t address)
        : _address(address)
    {
    }

    void start()
    {
        Wire.begin();
    }

    void writeByte(uint8_t subAddress, uint8_t data)
    {
        _wire.beginTransmission(_address);    // Initialize the Tx buffer
        _wire.write(subAddress);             // Put slave register address in Tx buffer
        _wire.write(data);                   // Put data in Tx buffer
        _err = _wire.endTransmission();  // Send the Tx buffer
        if (_err) printError();
    }

    uint8_t readByte(uint8_t subAddress)
    {
        uint8_t data = 0;                     // `data` will store the register data
        _wire.beginTransmission(_address);    // Initialize the Tx buffer
        _wire.write(subAddress);              // Put slave register address in Tx buffer
        _err = _wire.endTransmission(false);  // Send the Tx buffer, but send a restart to keep connection alive
        if (_err) printError();
        _wire.requestFrom(_address, (size_t)1);       // Read one byte from slave register address
        if (_wire.available()) data = _wire.read();  // Fill Rx buffer with result
        return data;                                 // Return data read from slave register
    }

    void readBytes(uint8_t subAddress, uint8_t count, uint8_t* dest)
    {
        _wire.beginTransmission(_address);    // Initialize the Tx buffer
        _wire.write(subAddress);              // Put slave register address in Tx buffer
        _err = _wire.endTransmission(false);  // Send the Tx buffer, but send a restart to keep connection alive
        if (_err) printError();
        uint8_t i = 0;
        _wire.requestFrom(_address, count);   // Read bytes from slave register address
        while (_wire.available()) {
            dest[i++] = _wire.read();
        }  // Put read results in the Rx buffer
    }

    void writeByte(uint8_t address, uint8_t subAddress, uint8_t data)
    {
        _wire.beginTransmission(address);    // Initialize the Tx buffer
        _wire.write(subAddress);             // Put slave register address in Tx buffer
        _wire.write(data);                   // Put data in Tx buffer
        _err = _wire.endTransmission();      // Send the Tx buffer
        if (_err) printError();
    }

    uint8_t readByte(uint8_t address, uint8_t subAddress)
    {
        uint8_t data = 0;                     // `data` will store the register data
        _wire.beginTransmission(address);     // Initialize the Tx buffer
        _wire.write(subAddress);              // Put slave register address in Tx buffer
        _err = _wire.endTransmission(false);  // Send the Tx buffer, but send a restart to keep connection alive
        if (_err) printError();
        _wire.requestFrom(address, (size_t)1);       // Read one byte from slave register address
        if (_wire.available()) data = _wire.read();  // Fill Rx buffer with result
        return data;                                 // Return data read from slave register
    }

    void readBytes(uint8_t address, uint8_t subAddress, uint8_t count, uint8_t* dest)
    {
        _wire.beginTransmission(address);     // Initialize the Tx buffer
        _wire.write(subAddress);              // Put slave register address in Tx buffer
        _err = _wire.endTransmission(false);  // Send the Tx buffer, but send a restart to keep connection alive
        if (_err) printError();
        uint8_t i = 0;
        _wire.requestFrom(address, count);  // Read bytes from slave register address
        while (_wire.available()) {
            dest[i++] = _wire.read();
        }  // Put read results in the Rx buffer
    }

    void printError()
    {
        if (_err == 7) return;  // to avoid stickbreaker-i2c branch's error code
        Serial.print("I2C ERROR CODE: ");
        Serial.println(_err);
    }

    uint8_t _address;
    uint8_t _err;
};