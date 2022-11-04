#pragma once

#include "Types.h"
#include <Wire.h>

//Magnetometer Registers
// #define AK8963_ADDRESS   0x0C
#define AK8963_WHO_AM_I  0x00 // should return 0x48
#define AK8963_INFO      0x01
#define AK8963_ST1       0x02  // data ready status bit 0
#define AK8963_XOUT_L	 0x03  // data
#define AK8963_XOUT_H	 0x04
#define AK8963_YOUT_L	 0x05
#define AK8963_YOUT_H	 0x06
#define AK8963_ZOUT_L	 0x07
#define AK8963_ZOUT_H	 0x08
#define AK8963_ST2       0x09  // Data overflow bit 3 and data read error status bit 2
#define AK8963_CNTL      0x0A  // Power down (0000), single-measurement (0001), self-test (1000) and Fuse ROM (1111) modes on bits 3:0
#define AK8963_ASTC      0x0C  // Self test control
#define AK8963_I2CDIS    0x0F  // I2C disable
#define AK8963_ASAX      0x10  // Fuse ROM x-axis sensitivity adjustment value
#define AK8963_ASAY      0x11  // Fuse ROM y-axis sensitivity adjustment value
#define AK8963_ASAZ      0x12  // Fuse ROM z-axis sensitivity adjustment value

#define SELF_TEST_X_GYRO 0x00
#define SELF_TEST_Y_GYRO 0x01
#define SELF_TEST_Z_GYRO 0x02

// #define X_FINE_GAIN      0x03 // [7:0] fine gain
// #define Y_FINE_GAIN      0x04
// #define Z_FINE_GAIN      0x05
// #define XA_OFFSET_H      0x06 // User-defined trim values for accelerometer
// #define XA_OFFSET_L_TC   0x07
// #define YA_OFFSET_H      0x08
// #define YA_OFFSET_L_TC   0x09
// #define ZA_OFFSET_H      0x0A
// #define ZA_OFFSET_L_TC   0x0B

#define SELF_TEST_X_ACCEL 0x0D
#define SELF_TEST_Y_ACCEL 0x0E
#define SELF_TEST_Z_ACCEL 0x0F

#define SELF_TEST_A      0x10

#define XG_OFFSET_H      0x13  // User-defined trim values for gyroscope
#define XG_OFFSET_L      0x14
#define YG_OFFSET_H      0x15
#define YG_OFFSET_L      0x16
#define ZG_OFFSET_H      0x17
#define ZG_OFFSET_L      0x18
#define SMPLRT_DIV       0x19
#define MPU_CONFIG       0x1A
#define GYRO_CONFIG      0x1B
#define ACCEL_CONFIG     0x1C
#define ACCEL_CONFIG2    0x1D
#define LP_ACCEL_ODR     0x1E
#define WOM_THR          0x1F

#define MOT_DUR          0x20  // Duration counter threshold for motion interrupt generation, 1 kHz rate, LSB = 1 ms
#define ZMOT_THR         0x21  // Zero-motion detection threshold bits [7:0]
#define ZRMOT_DUR        0x22  // Duration counter threshold for zero motion interrupt generation, 16 Hz rate, LSB = 64 ms

#define FIFO_EN          0x23
#define I2C_MST_CTRL     0x24
#define I2C_SLV0_ADDR    0x25
#define I2C_SLV0_REG     0x26
#define I2C_SLV0_CTRL    0x27
#define I2C_SLV1_ADDR    0x28
#define I2C_SLV1_REG     0x29
#define I2C_SLV1_CTRL    0x2A
#define I2C_SLV2_ADDR    0x2B
#define I2C_SLV2_REG     0x2C
#define I2C_SLV2_CTRL    0x2D
#define I2C_SLV3_ADDR    0x2E
#define I2C_SLV3_REG     0x2F
#define I2C_SLV3_CTRL    0x30
#define I2C_SLV4_ADDR    0x31
#define I2C_SLV4_REG     0x32
#define I2C_SLV4_DO      0x33
#define I2C_SLV4_CTRL    0x34
#define I2C_SLV4_DI      0x35
#define I2C_MST_STATUS   0x36
#define INT_PIN_CFG      0x37
#define INT_ENABLE       0x38
#define DMP_INT_STATUS   0x39  // Check DMP interrupt
#define INT_STATUS       0x3A
#define ACCEL_XOUT_H     0x3B
#define ACCEL_XOUT_L     0x3C
#define ACCEL_YOUT_H     0x3D
#define ACCEL_YOUT_L     0x3E
#define ACCEL_ZOUT_H     0x3F
#define ACCEL_ZOUT_L     0x40
#define TEMP_OUT_H       0x41
#define TEMP_OUT_L       0x42
#define GYRO_XOUT_H      0x43
#define GYRO_XOUT_L      0x44
#define GYRO_YOUT_H      0x45
#define GYRO_YOUT_L      0x46
#define GYRO_ZOUT_H      0x47
#define GYRO_ZOUT_L      0x48
#define EXT_SENS_DATA_00 0x49
#define EXT_SENS_DATA_01 0x4A
#define EXT_SENS_DATA_02 0x4B
#define EXT_SENS_DATA_03 0x4C
#define EXT_SENS_DATA_04 0x4D
#define EXT_SENS_DATA_05 0x4E
#define EXT_SENS_DATA_06 0x4F
#define EXT_SENS_DATA_07 0x50
#define EXT_SENS_DATA_08 0x51
#define EXT_SENS_DATA_09 0x52
#define EXT_SENS_DATA_10 0x53
#define EXT_SENS_DATA_11 0x54
#define EXT_SENS_DATA_12 0x55
#define EXT_SENS_DATA_13 0x56
#define EXT_SENS_DATA_14 0x57
#define EXT_SENS_DATA_15 0x58
#define EXT_SENS_DATA_16 0x59
#define EXT_SENS_DATA_17 0x5A
#define EXT_SENS_DATA_18 0x5B
#define EXT_SENS_DATA_19 0x5C
#define EXT_SENS_DATA_20 0x5D
#define EXT_SENS_DATA_21 0x5E
#define EXT_SENS_DATA_22 0x5F
#define EXT_SENS_DATA_23 0x60
#define MOT_DETECT_STATUS 0x61
#define I2C_SLV0_DO      0x63
#define I2C_SLV1_DO      0x64
#define I2C_SLV2_DO      0x65
#define I2C_SLV3_DO      0x66
#define I2C_MST_DELAY_CTRL 0x67
#define SIGNAL_PATH_RESET  0x68
#define MOT_DETECT_CTRL  0x69
#define USER_CTRL        0x6A  // Bit 7 enable DMP, bit 3 reset DMP
#define PWR_MGMT_1       0x6B // Device defaults to the SLEEP mode
#define PWR_MGMT_2       0x6C
#define DMP_BANK         0x6D  // Activates a specific bank in the DMP
#define DMP_RW_PNT       0x6E  // Set read/write pointer to a specific start address in specified DMP bank
#define DMP_REG          0x6F  // Register in DMP from which to read or to which to write
#define DMP_REG_1        0x70
#define DMP_REG_2        0x71
#define FIFO_COUNTH      0x72
#define FIFO_COUNTL      0x73
#define FIFO_R_W         0x74
#define WHO_AM_I_MPU9250 0x75 // Should return 0x71
#define XA_OFFSET_H      0x77
#define XA_OFFSET_L      0x78
#define YA_OFFSET_H      0x7A
#define YA_OFFSET_L      0x7B
#define ZA_OFFSET_H      0x7D
#define ZA_OFFSET_L      0x7E

static constexpr uint8_t MPU9250_DEFAULT_ADDRESS {0x68};  // Device address when ADO = 0
static constexpr uint8_t MPU9250_WHOAMI_DEFAULT_VALUE {0x71};

TwoWire& _wire = Wire;

class Bus
{
public:
    Bus(uint8_t address)
        : _address(address)
    {
    }

    void writeByte(uint8_t subAddress, uint8_t data) {
        _wire.beginTransmission(_address);    // Initialize the Tx buffer
        _wire.write(subAddress);             // Put slave register address in Tx buffer
        _wire.write(data);                   // Put data in Tx buffer
        _err = _wire.endTransmission();  // Send the Tx buffer
        if (_err) printError();
    }

    uint8_t readByte(uint8_t subAddress) {
        uint8_t data = 0;                         // `data` will store the register data
        _wire.beginTransmission(_address);         // Initialize the Tx buffer
        _wire.write(subAddress);                  // Put slave register address in Tx buffer
        _err = _wire.endTransmission(false);  // Send the Tx buffer, but send a restart to keep connection alive
        if (_err) printError();
        _wire.requestFrom(_address, (size_t)1);       // Read one byte from slave register address
        if (_wire.available()) data = _wire.read();  // Fill Rx buffer with result
        return data;                                 // Return data read from slave register
    }

    void readBytes(uint8_t subAddress, uint8_t count, uint8_t* dest) {
        _wire.beginTransmission(_address);         // Initialize the Tx buffer
        _wire.write(subAddress);                  // Put slave register address in Tx buffer
        _err = _wire.endTransmission(false);  // Send the Tx buffer, but send a restart to keep connection alive
        if (_err) printError();
        uint8_t i = 0;
        _wire.requestFrom(_address, count);  // Read bytes from slave register address
        while (_wire.available()) {
            dest[i++] = _wire.read();
        }  // Put read results in the Rx buffer
    }

    void printError() {
        if (_err == 7) return;  // to avoid stickbreaker-i2c branch's error code
        Serial.print("I2C ERROR CODE : ");
        Serial.println(_err);
    }

    uint8_t _address;
    uint8_t _err;
};




class MPU9250
{
public:
    enum class FIFO_SAMPLE_RATE : uint8_t {
        SMPL_1000HZ,
        SMPL_500HZ,
        SMPL_333HZ,
        SMPL_250HZ,
        SMPL_200HZ,
        SMPL_167HZ,
        SMPL_143HZ,
        SMPL_125HZ,
    };

    enum class GYRO_DLPF_CFG : uint8_t {
        DLPF_250HZ,
        DLPF_184HZ,
        DLPF_92HZ,
        DLPF_41HZ,
        DLPF_20HZ,
        DLPF_10HZ,
        DLPF_5HZ,
        DLPF_3600HZ,
    };

    enum class GYRO_FS_SEL {
        G250DPS,
        G500DPS,
        G1000DPS,
        G2000DPS
    };

    MPU9250(uint8_t address = MPU9250_DEFAULT_ADDRESS)
        : _bus(address)
        , _verbose(true)
        , _hasConnected(false)
        , _t(_bus)
        , _a(_bus)
        , _g(_bus)
    {
    }

    void setup()
    {
        Serial.println("MPU9250::setup()");

        // addr should be valid for MPU
        if ((_bus._address < MPU9250_DEFAULT_ADDRESS) || (_bus._address > MPU9250_DEFAULT_ADDRESS + 7)) {
            Serial.print("I2C address 0x");
            Serial.print(_bus._address, HEX);
            Serial.println(" is not valid for MPU. Please check your I2C address.");
        }

        wait();
        init();
    }

    void wait()
    {
        while(!isConnected()) {
            if (_verbose) {
                uint8_t counter = 0;
                char buffer[50];
                sprintf(buffer, "[%d] MPU9250::wait(); awaitng for MPU...", counter);
                Serial.println(buffer);
                delay(1000);
            }            
        }
    }
 
    bool isConnected() {
        byte c = _bus.readByte(WHO_AM_I_MPU9250);
        bool b = (c == MPU9250_WHOAMI_DEFAULT_VALUE);
        //b |= (c == MPU9255_WHOAMI_DEFAULT_VALUE);
        //b |= (c == MPU6500_WHOAMI_DEFAULT_VALUE);
        if (_verbose) {
            if (b) {
                Serial.print("MPU9250::isConnected(); MPU is connected; WHO_AM_I_MPU9250=");
                Serial.println(c, HEX);
            } else {
                Serial.print("MPU9250::isConnected(); MPU is NOT connected; WHO_AM_I_MPU9250=");
                Serial.println(c, HEX);                
            }
        }
       return b;
    }

    void init()
    {
        Serial.println("MPU9250::init()");

        //acc_resolution = get_acc_resolution(setinting.accel_fs_sel);
        //gyro_resolution = get_gyro_resolution(setting.gyro_fs_sel);
        //mag_resolution = get_mag_resolution(setting.mag_output_bits);

        // reset device
        _bus.writeByte(PWR_MGMT_1, 0x80);  // Write a one to bit 7 reset bit; toggle reset device
        delay(200);

         // wake up device
        _bus.writeByte(PWR_MGMT_1, 0x00);  // Clear sleep mode bit (6), enable all sensors
        delay(200);                             // Wait for all registers to reset

        // get stable time source
        _bus.writeByte(PWR_MGMT_1, 0x01);  // Auto select clock source to be PLL gyroscope reference if ready else
        delay(200);



        // Configure Gyro and Thermometer
        // Disable FSYNC and set thermometer and gyro bandwidth to 41 and 42 Hz, respectively;
        // minimum delay time for this setting is 5.9 ms, which means sensor fusion update rates cannot
        // be higher than 1 / 0.0059 = 170 Hz
        // GYRO_DLPF_CFG = bits 2:0 = 011; this limits the sample rate to 1000 Hz for both
        // With the MPU9250, it is possible to get gyro sample rates of 32 kHz (!), 8 kHz, or 1 kHz
        _bus.writeByte(MPU_CONFIG, (uint8_t)GYRO_DLPF_CFG::DLPF_41HZ);

        // Set sample rate = gyroscope output rate/(1 + SMPLRT_DIV)
        _bus.writeByte(SMPLRT_DIV, (uint8_t)FIFO_SAMPLE_RATE::SMPL_200HZ);  // Use a 200 Hz rate; a rate consistent with the filter update rate
                                                                            // determined inset in CONFIG above

        // Set gyroscope full scale range
        // Range selects FS_SEL and GFS_SEL are 0 - 3, so 2-bit values are left-shifted into positions 4:3
        uint8_t c = _bus.readByte(GYRO_CONFIG);  // get current GYRO_CONFIG register value
        c = c & ~0xE0;                                // Clear self-test bits [7:5]
        c = c & ~0x03;                                // Clear Fchoice bits [1:0]
        c = c & ~0x18;                                // Clear GYRO_FS_SEL bits [4:3]
        c = c | (uint8_t(GYRO_FS_SEL::G250DPS) << 3); // Set 250DPS range for the gyro
        c = c | (uint8_t(~0x3) & 0x03);               // Set Fchoice for the gyro
        _bus.writeByte(GYRO_CONFIG, c);

        // Set accelerometer full-scale range configuration
        c = _bus.readByte(ACCEL_CONFIG); // get current ACCEL_CONFIG register value
        c = c & ~0xE0;                                 // Clear self-test bits [7:5]
        c = c & ~0x18;                                 // Clear ACCEL_FS_SEL bits [4:3]
        c = c | (uint8_t(Accelerometer::Scale::_4G) << 3);  // Set 4G scale range for the accelerometer
        _bus.writeByte(ACCEL_CONFIG, c);     // Write new ACCEL_CONFIG register value

        // Set accelerometer sample rate configuration
        // It is possible to get a 4 kHz sample rate from the accelerometer by choosing 1 for
        // accel_fchoice_b bit [3]; in this case the bandwidth is 1.13 kHz
        c = _bus.readByte(ACCEL_CONFIG2);  // get current ACCEL_CONFIG2 register value
        c = c & ~0x0F;                                     // Clear accel_fchoice_b (bit 3) and A_DLPFG (bits [2:0])
        c = c | (~(1 << 3) & 0x08);                                      // Set accel_fchoice_b to 1
        c = c | (uint8_t(Accelerometer::DLPF::_45HZ) & 0x07);  // Set accelerometer rate to 1 kHz and bandwidth to 41 Hz
        _bus.writeByte(ACCEL_CONFIG2, c);        // Write new ACCEL_CONFIG2 register value


        // Configure Interrupts and Bypass Enable
        // Set interrupt pin active high, push-pull, hold interrupt pin level HIGH until interrupt cleared,
        // clear on read of INT_STATUS, and enable I2C_BYPASS_EN so additional chips
        // can join the I2C bus and all can be controlled by the Arduino as master
        _bus.writeByte(INT_PIN_CFG, 0x22);
        _bus.writeByte(INT_ENABLE, 0x01);  // Enable data ready (bit 0) interrupt
        delay(100);
    }

    void update()
    {
        _t.update();
        _a.update();
        _g.update();
    }    

private:
    bool    _verbose;
    bool    _hasConnected;

    class Temperature
    {
    private:
        Bus& _bus;
        uint16_t _registers[3];
    public:
        Temperature(Bus& bus)
            : _bus(bus)
            , _registers({0, 0, 0})
        {
        }

        void read(int16_t* destination) {
            uint8_t raw[2];                                              // x/y/z accel register data stored here
            _bus.readBytes(TEMP_OUT_H, 2, &raw[0]);             // Read the 6 raw data registers into data array
            destination[0] = ((int16_t)raw[0] << 8) | (int16_t)raw[1];  // Turn the MSB and LSB into a signed 16-bit value
        }

        void update()
        {
            read(_registers);  // INT cleared on any read
            char buffer[50];
            sprintf(buffer, "Temperature, t:%d", _registers[0]);
            Serial.println(buffer);
        }
    };        



    class Accelerometer
    {
    private:
        Bus& _bus;
        uint16_t _registers[3];
    public:
        Accelerometer(Bus& bus)
            : _bus(bus)
            , _registers({0, 0, 0})
        {
        }

        enum class Scale : uint8_t {
            _2G = 0,
            _4G,
            _8G,
            _16G
        };

        enum class DLPF : uint8_t {
            _218HZ_0,
            _218HZ_1,
            _99HZ,
            _45HZ,
            _21HZ,
            _10HZ,
            _5HZ,
            F_420HZ,
        };

        void read(int16_t* destination) {
            uint8_t raw[6];                                              // x/y/z accel register data stored here
            _bus.readBytes(ACCEL_XOUT_H, 6, &raw[0]);             // Read the 6 raw data registers into data array
            destination[0] = ((int16_t)raw[0] << 8) | (int16_t)raw[1];  // Turn the MSB and LSB into a signed 16-bit value
            destination[1] = ((int16_t)raw[2] << 8) | (int16_t)raw[3];
            destination[2] = ((int16_t)raw[4] << 8) | (int16_t)raw[5];
        }

        void update()
        {
            read(_registers);  // INT cleared on any read
            char buffer[50];
            sprintf(buffer, "Accelerometer, X:%d, Y:%d, Z:%d", _registers[0], _registers[1], _registers[2]);
            Serial.println(buffer);
        }
    };




    class Gyroscope
    {
    private:
        Bus& _bus;
        uint16_t _registers[3];
    public:
        Gyroscope(Bus& bus)
            : _bus(bus)
            , _registers({0, 0, 0})
        {
        }

        void read(int16_t* destination) {
            uint8_t raw[6];                                              // x/y/z accel register data stored here
            _bus.readBytes(GYRO_XOUT_H, 6, &raw[0]);             // Read the 6 raw data registers into data array
            destination[0] = ((int16_t)raw[0] << 8) | (int16_t)raw[1];  // Turn the MSB and LSB into a signed 16-bit value
            destination[1] = ((int16_t)raw[2] << 8) | (int16_t)raw[3];
            destination[2] = ((int16_t)raw[4] << 8) | (int16_t)raw[5];
        }

        void update()
        {
            read(_registers);  // INT cleared on any read
            char buffer[50];
            sprintf(buffer, "Gyroscope, X:%d, Y:%d, Z:%d", _registers[0], _registers[1], _registers[2]);
            Serial.println(buffer);
        }
    };



    class Magnitometer
    {
    private:
        Bus& _bus;
        uint16_t _registers[3];
    public:
        Magnitometer(Bus& bus)
            : _bus(bus)
            , _registers({0, 0, 0})
        {
        }

        enum Mscale {
            MFS_14BITS = 0, // 0.6 mG per LSB
            MFS_16BITS      // 0.15 mG per LSB
        };

        void read(int16_t* destination) {
            uint8_t raw[6];                                              // x/y/z accel register data stored here
            _bus.readBytes(ACCEL_XOUT_H, 6, &raw[0]);             // Read the 6 raw data registers into data array
            destination[0] = ((int16_t)raw[0] << 8) | (int16_t)raw[1];  // Turn the MSB and LSB into a signed 16-bit value
            destination[1] = ((int16_t)raw[2] << 8) | (int16_t)raw[3];
            destination[2] = ((int16_t)raw[4] << 8) | (int16_t)raw[5];
            destination[3] = ((int16_t)raw[6] << 8) | (int16_t)raw[7];
            destination[4] = ((int16_t)raw[8] << 8) | (int16_t)raw[9];
            destination[5] = ((int16_t)raw[10] << 8) | (int16_t)raw[11];
        }

        void update()
        {
            read(_registers);  // INT cleared on any read
            char buffer[50];
            sprintf(buffer, "Accelerometer, X:%d, Y:%d, Z:%d", _registers[0], _registers[1], _registers[2]);
            Serial.println(buffer);
        }
    };

public:

    Bus _bus;
    Temperature   _t;
    Accelerometer _a;
    Gyroscope     _g;

};
