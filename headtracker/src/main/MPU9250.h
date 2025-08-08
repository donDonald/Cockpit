#pragma once

#include "Types.h"
#include "Bus.h"

char *dtostrf_ex(
    double val,
    signed char width,
    unsigned char prec,
    char *s)
{
    char* result = dtostrf(val, width, prec, s);
    while(*result == ' ')
        ++result;
    return result;
}

#define SMPLRT_DIV       0x19
#define MPU_CONFIG       0x1A
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

static constexpr uint8_t MPU9250_DEFAULT_ADDRESS {0x68};  // Device address when ADO = 0
static constexpr uint8_t MPU9250_WHOAMI_DEFAULT_VALUE {0x71};

#define MPU_T_UPDATE
#define MPU_G_UPDATE
#define MPU_A_UPDATE
//#define MPU_M_UPDATE

#define MPU_T_PRINT
#define MPU_G_PRINT
#define MPU_A_PRINT
//#define MPU_M_PRINT

//#define T_LOGGER_ENABLE
//#define G_LOGGER_ENABLE
//#define A_LOGGER_ENABLE
//#define M_LOGGER_ENABLE

char g_buffer[80]; // Common buffer for formatting

class MPU9250
{
public: // types
    struct Point
    {
        float x, y, z;
    };

    enum class FIFO_SAMPLE_RATE : uint8_t
    {
        SMPL_1000HZ,
        SMPL_500HZ,
        SMPL_333HZ,
        SMPL_250HZ,
        SMPL_200HZ,
        SMPL_167HZ,
        SMPL_143HZ,
        SMPL_125HZ,
    };

    enum class GYRO_DLPF_CFG : uint8_t
    {
        DLPF_250HZ,
        DLPF_184HZ,
        DLPF_92HZ,
        DLPF_41HZ,
        DLPF_20HZ,
        DLPF_10HZ,
        DLPF_5HZ,
        DLPF_3600HZ,
    };

    enum class GYRO_FS_SEL 
    {
        G250DPS,
        G500DPS,
        G1000DPS,
        G2000DPS
    };

public:
    MPU9250(Bus& bus)
        : _bus(bus)
#ifdef MPU_T_UPDATE
        , _t(_bus)
#endif
#ifdef MPU_G_UPDATE
        , _g(_bus)
#endif
#ifdef MPU_A_UPDATE
        , _a(_bus)
#endif
#ifdef MPU_M_UPDATE
        , _m(_bus)
#endif
    {
    }

    void setup()
    {
        Serial.println("MPU9250::setup()");

        // addr should be valid for MPU
        if ((_bus._address < MPU9250_DEFAULT_ADDRESS) ||
            (_bus._address > MPU9250_DEFAULT_ADDRESS + 7))
        {
            Serial.print("I2C address 0x");
            Serial.print(_bus._address, HEX);
            Serial.println(" is not valid for MPU. Please check your I2C address.");
        }
        wait();

        // reset device
        _bus.writeByte(PWR_MGMT_1, 0x80);  // Write a one to bit 7 reset bit; toggle reset device
        delay(200);

         // wake up device
        _bus.writeByte(PWR_MGMT_1, 0x00);  // Clear sleep mode bit (6), enable all sensors
        delay(200); // Wait for all registers to reset

        // get stable time source
        _bus.writeByte(PWR_MGMT_1, 0x01);  // Auto select clock source to be PLL gyroscope reference if ready else
        delay(200);

#ifdef MPU_T_UPDATE
        _t.setup();
#endif
#ifdef MPU_G_UPDATE
        _g.setup();
#endif
#ifdef MPU_A_UPDATE
        _a.setup();
#endif
#ifdef MPU_M_UPDATE
        _m.setup();
#endif

#if 0
        // Configure Interrupts and Bypass Enable
        // Set interrupt pin active high, push-pull, hold interrupt pin level HIGH until interrupt cleared,
        // clear on read of INT_STATUS, and enable I2C_BYPASS_EN so additional chips
        // can join the I2C bus and all can be controlled by the Arduino as master
        _bus.writeByte(INT_PIN_CFG, 0x22);
        _bus.writeByte(INT_ENABLE, 0x01);  // Enable data ready (bit 0) interrupt
        delay(100);
#endif
    }

    void wait()
    {
        while(!isConnected())
        {
            if (true)
            {
                uint8_t counter = 0;
                sprintf(g_buffer, "[%d] MPU9250::wait(); awaitng for MPU...", counter);
                Serial.println(g_buffer);
            }            
            delay(1000);
        }
    }
 
    bool isConnected()
    {
        byte c = _bus.readByte(WHO_AM_I_MPU9250);
        bool b = (c == MPU9250_WHOAMI_DEFAULT_VALUE);
        if (b)
        {
            Serial.print("MPU9250::isConnected(); MPU is connected; WHO_AM_I_MPU9250=");
            Serial.println(c, HEX);
        }
        else
        {
            Serial.print("MPU9250::isConnected(); MPU is NOT connected; WHO_AM_I_MPU9250=");
            Serial.println(c, HEX);                
        }
        return b;
    }

    void update()
    {
#ifdef MPU_T_UPDATE
        float t;
        _t.update(t);
#endif

#ifdef MPU_G_UPDATE
        Point g;
        _g.update(g);
#endif

#ifdef MPU_A_UPDATE
        Point a;
        _a.update(a);
#endif

#ifdef MPU_M_UPDATE
        Point m;
        _m.update(m);
#endif

#ifdef MPU_T_PRINT
        _t.print(t);
#endif

#ifdef MPU_G_PRINT
        _g.print(g);
#endif

#ifdef MPU_A_PRINT
        _a.print(a);
#endif

#ifdef MPU_M_PRINT
        _m.print(m);
#endif
    }

private:




    // #######################################################################
    class Temperature
    {
    private:
        // registers
        #define TEMP_OUT_H       0x41
        #define TEMP_OUT_L       0x42

        Bus& _bus;
        uint16_t _registers[1];

    public:
        Temperature(Bus& bus)
            : _bus(bus)
            , _registers({0})
        {
        }

        void setup()
        {
            Serial.println("MPU9250::Temperature::setup()");
        }

        void read(int16_t* destination)
        {
            uint8_t raw[2];
            _bus.readBytes(TEMP_OUT_H, 2, &raw[0]); // Read the 2 raw data registers
            destination[0] = ((int16_t)raw[0] << 8) | (int16_t)raw[1];
        }

        void update(float& value)
        {
            read(_registers); 
            value = ((float)_registers[0]) / 333.87 + 17.0;  // Temperature in degrees Centigrade

#ifdef T_LOGGER_ENABLE
            log(value);
#endif
        }

        void print(float& value) const
        {
            char szT[15];
            char* result_t = dtostrf_ex(value, 7, 1, szT);
            sprintf(g_buffer,"{t:%s}", result_t);
            Serial.println(g_buffer);
        }

    private:
#ifdef T_LOGGER_ENABLE
        void log(const float& value) const
        {
            char szValue[6];
            dtostrf(value, 6, 2, szValue);
            sprintf(g_buffer, "Temperature, t(int):%d, t(float):%s", _registers[0], szValue);
            Serial.println(g_buffer);
        }
#endif
    };        




    // #######################################################################
    class Gyroscope
    {
    private:
        // registers
        #define SELF_TEST_X_GYRO 0x00
        #define SELF_TEST_Y_GYRO 0x01
        #define SELF_TEST_Z_GYRO 0x02
        #define XG_OFFSET_H      0x13  // User-defined trim values for gyroscope
        #define XG_OFFSET_L      0x14
        #define YG_OFFSET_H      0x15
        #define YG_OFFSET_L      0x16
        #define ZG_OFFSET_H      0x17
        #define ZG_OFFSET_L      0x18
        #define GYRO_CONFIG      0x1B
        #define GYRO_XOUT_H      0x43
        #define GYRO_XOUT_L      0x44
        #define GYRO_YOUT_H      0x45
        #define GYRO_YOUT_L      0x46
        #define GYRO_ZOUT_H      0x47
        #define GYRO_ZOUT_L      0x48

        Bus& _bus;
        int16_t _registers[3];
        float _resolution;
    public:
        Gyroscope(Bus& bus)
            : _bus(bus)
            , _registers({0, 0, 0})
        {
        }

        void setup()
        {
            Serial.println("MPU9250::Gyroscope::setup()");
            //  250 DPS ;  rate=(1 kHz/5)=200 Hz ; bandwidth=20 Hz

            static constexpr GYRO_FS_SEL range = GYRO_FS_SEL::G250DPS;
            static constexpr GYRO_DLPF_CFG dlpf = GYRO_DLPF_CFG::DLPF_20HZ;
            _resolution = resolution(range);
            
            // Configure Gyro and Thermometer
            // Disable FSYNC and set thermometer and gyro bandwidth to 20 and 20 Hz respectively;
            // GYRO_DLPF_CFG = bits 2:0 = b100; this limits the sample rate to 1000 Hz for both
            _bus.writeByte(MPU_CONFIG, (uint8_t)dlpf);

            // Set sample rate = gyroscope output rate/(1 + SMPLRT_DIV)
            // Use a 200 Hz rate; a rate consistent with the filter update rate determined inset in CONFIG above
            _bus.writeByte(SMPLRT_DIV, (uint8_t)FIFO_SAMPLE_RATE::SMPL_200HZ); 

            // Set gyroscope to 250DPS ad 20Hz Bandwidth
            // Range selects FS_SEL and GFS_SEL are 0 - 3, so 2-bit values are left-shifted into positions 4:3
            uint8_t c = _bus.readByte(GYRO_CONFIG);  // get current GYRO_CONFIG register value
            c = c & ~0xE0;                                // Clear self-test bits [7:5]
            c = c & ~0x18;                                // Clear GYRO_FS_SEL bits [4:3]
            c = c & ~0x03;                                // Clear Fchoice bits [1:0]
            c = c | (uint8_t(range) << 3); // Set 250DPS range for the gyro
            c = c | (uint8_t(~0x3) & 0x03);               // Set Fchoice to b11 targeting keeping 20Hz in mind 

            _bus.writeByte(GYRO_CONFIG, c);
        }

        void read(int16_t* destination)
        {
            uint8_t raw[6];
            _bus.readBytes(GYRO_XOUT_H, 6, &raw[0]); // Read the 6 raw data registers into data array
            destination[0] = ((int16_t)raw[0] << 8) | (int16_t)raw[1];
            destination[1] = ((int16_t)raw[2] << 8) | (int16_t)raw[3];
            destination[2] = ((int16_t)raw[4] << 8) | (int16_t)raw[5];
        }

        //void update(float& x, float& y, float& z)
        void update(Point& value)
        {
            read(_registers); // INT cleared on any read

            value.x = _registers[0];
            value.y = _registers[1];
            value.z = _registers[2];
            value.x *= _resolution;
            value.y *= _resolution;
            value.z *= _resolution;

#ifdef G_LOGGER_ENABLE
            log(value);
#endif
        }

        void print(const Point& value) const
        {
            char szX[15];
            char szY[15];
            char szZ[15];
            char* result_x = dtostrf_ex(value.x, 8, 2, szX);
            char* result_y = dtostrf_ex(value.y, 8, 2, szY);
            char* result_z = dtostrf_ex(value.z, 8, 2, szZ);
            sprintf(g_buffer,"{g:{x:%s, y:%s, z:%s}}", result_x, result_y, result_z);
            Serial.println(g_buffer);
        }

    private:
#ifdef G_LOGGER_ENABLE
        void log(const Point& value) const
        {
            char szX[20];
            char szY[20];
            char szZ[20];
            dtostrf(value.x, 11, 4, szX);
            dtostrf(value.y, 11, 4, szY);
            dtostrf(value.z, 11, 4, szZ);
            sprintf(g_buffer, "Gyroscope(%s, %s, %s)", szX, szY, szZ);
            Serial.println(g_buffer);
        }
#endif

        float resolution(const GYRO_FS_SEL gyro_fs_sel) const
        {
            switch (gyro_fs_sel) {
                // Possible gyro scales (and their register bit settings) are:
                // 250 DPS (00), 500 DPS (01), 1000 DPS (10), and 2000 DPS  (11).
                // Here's a bit of an algorith to calculate DPS/(ADC tick) based on that 2-bit value:
                case GYRO_FS_SEL::G250DPS:
                    return 250.0 / 32768.0;
                case GYRO_FS_SEL::G500DPS:
                    return 500.0 / 32768.0;
                case GYRO_FS_SEL::G1000DPS:
                    return 1000.0 / 32768.0;
                case GYRO_FS_SEL::G2000DPS:
                    return 2000.0 / 32768.0;
                default:
                    return 0.;
            }          
        }
    };




    // #######################################################################
    class Accelerometer
    {
    private:
        // registers
        #define SELF_TEST_X_ACCEL 0x0D
        #define SELF_TEST_Y_ACCEL 0x0E
        #define SELF_TEST_Z_ACCEL 0x0F
        #define ACCEL_CONFIG      0x1C
        #define ACCEL_CONFIG2     0x1D
        #define LP_ACCEL_ODR      0x1E
        #define ACCEL_XOUT_H      0x3B
        #define ACCEL_XOUT_L      0x3C
        #define ACCEL_YOUT_H      0x3D
        #define ACCEL_YOUT_L      0x3E
        #define ACCEL_ZOUT_H      0x3F
        #define ACCEL_ZOUT_L      0x40
        #define XA_OFFSET_H       0x77
        #define XA_OFFSET_L       0x78
        #define YA_OFFSET_H       0x7A
        #define YA_OFFSET_L       0x7B
        #define ZA_OFFSET_H       0x7D
        #define ZA_OFFSET_L       0x7E

        Bus& _bus;
        int16_t _registers[3];
        float _resolution;

    public:
        Accelerometer(Bus& bus)
            : _bus(bus)
            , _registers({0, 0, 0})
            , _resolution(0)
        {
        }

        enum class ACCEL_FS_SEL : uint8_t
        {
            _2G = 0,
            _4G,
            _8G,
            _16G
        };

        enum class DLPF : uint8_t
        {
            _218HZ_0,
            _218HZ_1,
            _99HZ,
            _45HZ,
            _21HZ,
            _10HZ,
            _5HZ,
            F_420HZ,
        };

        void setup()
        {
            Serial.println("MPU9250::Accelerometer::setup()");
            //  2G ;  rate=(1 kHz/5)=200 Hz; bandwidth=21 Hz

            static constexpr Accelerometer::ACCEL_FS_SEL range = Accelerometer::ACCEL_FS_SEL::_2G;
            static constexpr Accelerometer::DLPF dlpf = Accelerometer::DLPF::_21HZ;
            _resolution = resolution(range);

            // Set accelerometer full-scale range configuration
            uint8_t c;
            c = _bus.readByte(ACCEL_CONFIG); // get current ACCEL_CONFIG register value
            c = c & ~0xE0;                                 // Clear self-test bits [7:5]
            c = c & ~0x18;                                 // Clear ACCEL_FS_SEL bits [4:3]
            c = c | (uint8_t(range) << 3);  // Set range for the accelerometer
            _bus.writeByte(ACCEL_CONFIG, c);     // Write new ACCEL_CONFIG register value

            // Set accelerometer sample rate configuration
            // It is possible to get a 4 kHz sample rate from the accelerometer by choosing 1 for
            // accel_fchoice_b bit [3]; in this case the bandwidth is 1.13 kHz
            c = _bus.readByte(ACCEL_CONFIG2);  // get current ACCEL_CONFIG2 register value
            c = c & 0x0F0;                     // Clear accel_fchoice_b (bit 3) and A_DLPFG (bits [2:0])
            c = c | (~(1 << 3) & 0x08);        // Set accel_fchoice_b
            c = c | uint8_t(dlpf);  // Set accelerometer rate to 1 kHz and bandwidth to 21 Hz
            _bus.writeByte(ACCEL_CONFIG2, c);  // Write new ACCEL_CONFIG2 register value
        }

        void read(int16_t* destination)
        {
            uint8_t raw[6];                                              // x/y/z accel register data stored here
            _bus.readBytes(ACCEL_XOUT_H, 6, &raw[0]);             // Read the 6 raw data registers into data array
            destination[0] = ((int16_t)raw[0] << 8) | (int16_t)raw[1];  // Turn the MSB and LSB into a signed 16-bit value
            destination[1] = ((int16_t)raw[2] << 8) | (int16_t)raw[3];
            destination[2] = ((int16_t)raw[4] << 8) | (int16_t)raw[5];
        }

        void update(Point& value)
        {
            read(_registers);

            value.x = _registers[0];
            value.y = _registers[1];
            value.z = _registers[2];
            value.x *= _resolution;
            value.y *= _resolution;
            value.z *= _resolution;

#ifdef A_LOGGER_ENABLE
            log(value);
#endif
        }

        void print(const Point& value) const
        {
            char szX[15];
            char szY[15];
            char szZ[15];
            char* result_x = dtostrf_ex(value.x, 8, 2, szX);
            char* result_y = dtostrf_ex(value.y, 8, 2, szY);
            char* result_z = dtostrf_ex(value.z, 8, 2, szZ);
            sprintf(g_buffer,"{a:{x:%s, y:%s, z:%s}}", result_x, result_y, result_z);
            Serial.println(g_buffer);
        }

    private:
#ifdef A_LOGGER_ENABLE
        void log(const Point& value) const
        {
            char szX[20];
            char szY[20];
            char szZ[20];
            dtostrf(value.x, 11, 4, szX);
            dtostrf(value.y, 11, 4, szY);
            dtostrf(value.z, 11, 4, szZ);
            sprintf(g_buffer, "Accelerometer(%s, %s, %s)", szX, szY, szZ);
            Serial.println(g_buffer);
        }
#endif

        float resolution(const ACCEL_FS_SEL accel_af_sel) const
        {
            switch (accel_af_sel)
            {
                // Possible accelerometer scales (and their register bit settings) are:
                // 2 Gs (00), 4 Gs (01), 8 Gs (10), and 16 Gs  (11).
                // Here's a bit of an algorith to calculate DPS/(ADC tick) based on that 2-bit value:
                case ACCEL_FS_SEL::_2G :
                    return 2.0 / 32768.0;
                case ACCEL_FS_SEL::_4G:
                    return 4.0 / 32768.0;
                case ACCEL_FS_SEL::_8G:
                    return 8.0 / 32768.0;
                case ACCEL_FS_SEL::_16G:
                    return 16.0 / 32768.0;
                default:
                    return 0.;
            }
        }
    };




    // #######################################################################

    class Magnitometer
    {
    private:
        // registers
        #define AK8963_ADDRESS   0x0C
        #define AK8963_WHO_AM_I  0x00 // should return 0x48
        #define AK8963_WIA       0x00
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

        Bus& _bus;
        int16_t _registers[3];
        float _resolution;
        float _biasFactory[3] {0., 0., 0.};
        static constexpr uint8_t AK8963_WHOAMI_DEFAULT_VALUE {0x48};

    public:
        enum class MAG_OUTPUT_BITS : uint8_t
        {
            _14BITS,
            _16BITS
        };

        Magnitometer(Bus& bus)
            : _bus(bus)
            , _registers({0, 0, 0})
        {
        }

        void setup()
        {  
            Serial.println("MPU9250::Magnitometer::setup()");
            // 100 Hz / 16 Bits            

            if (true)
            {
                uint8_t v =  _bus.readByte(AK8963_ADDRESS, AK8963_WIA);
                sprintf(g_buffer, "MPU9250::Magnitometer::setup(), WIA:%02X", v);
                Serial.println(g_buffer);
            }
            if (true)
            {
                uint8_t v =  _bus.readByte(AK8963_ADDRESS, AK8963_INFO);
                sprintf(g_buffer, "MPU9250::Magnitometer::setup(), INFO:%02X", v);
                Serial.println(g_buffer);
            }
            if (true)
            {
                uint8_t v =  _bus.readByte(AK8963_ADDRESS, AK8963_ST1);
                sprintf(g_buffer, "MPU9250::Magnitometer::setup(), ST1:%02X", v);
                Serial.println(g_buffer);
            }
            if (true)
            {
                uint8_t v =  _bus.readByte(AK8963_ADDRESS, AK8963_ST2);
                sprintf(g_buffer, "MPU9250::Magnitometer::setup(), ST1:%02X", v);
                Serial.println(g_buffer);
            }

            static constexpr uint8_t MODE {0x06};  // 0x01 for Single measurement mode, 0x02 for 8 Hz, 0x06 for 100 Hz continuous magnetometer data read
            static constexpr MAG_OUTPUT_BITS RESOLUTION = MAG_OUTPUT_BITS::_16BITS;
            _resolution = resolution(RESOLUTION);

            // First extract the factory calibration for each magnetometer axis
            uint8_t data[3];                            // x/y/z gyro calibration data stored here
            _bus.writeByte(AK8963_ADDRESS, AK8963_CNTL, 0x00);  // Power down magnetometer
            delay(10);

            _bus.writeByte(AK8963_ADDRESS, AK8963_CNTL, 0x0F);  // Enter Fuse ROM access mode
            delay(10);

            _bus.readBytes(AK8963_ADDRESS, AK8963_ASAX, 3, &data[0]); // Read the x-, y-, and z-axis calibration values

            _biasFactory[0] = (float)(data[0] - 128) / 256. + 1.;  // Return x-axis sensitivity adjustment values, etc.
            _biasFactory[1] = (float)(data[1] - 128) / 256. + 1.;
            _biasFactory[2] = (float)(data[2] - 128) / 256. + 1.;
            _bus.writeByte(AK8963_ADDRESS, AK8963_CNTL, 0x00);  // Power down magnetometer
            delay(10);
/*
            // Configure the magnetometer for continuous read and highest resolution
            // set Mscale bit 4 to 1 (0) to enable 16 (14) bit resolution in CNTL register,
            // and enable continuous mode data acquisition MAG_MODE (bits [3:0]), 0010 for 8 Hz and 0110 for 100 Hz sample rates
            _bus.writeByte(AK8963_ADDRESS, AK8963_CNTL, (uint8_t)RESOLUTION << 4 | MODE);
*/

            if (true)
            {
                Serial.print("MPU9250::Magnitometer::setup(); X-Axis sensitivity offset value:");
                Serial.println(_biasFactory[0], 2);
                Serial.print("MPU9250::Magnitometer::setup(); Y-Axis sensitivity offset value:");
                Serial.println(_biasFactory[1], 2);
                Serial.print("MPU9250::Magnitometer::setup(); A-Axis sensitivity offset value:");
                Serial.println(_biasFactory[2], 2);
            }

            if (true)
            {
                char g_buffer[50];
                uint8_t v =  _bus.readByte(AK8963_ADDRESS, AK8963_INFO);
                sprintf(g_buffer, "AK8963::INF0:%02X", v);
            }
            if (true)
            {
                char g_buffer[50];
                uint8_t v =  _bus.readByte(AK8963_ADDRESS, AK8963_ST1);
                sprintf(g_buffer, "AK8963::ST1:%02X", v);
            }
            if (true)
            {
                char g_buffer[50];
                uint8_t v =  _bus.readByte(AK8963_ADDRESS, AK8963_ST2);
                sprintf(g_buffer, "AK8963::ST2:%02X", v);
            }
        }

        void wait()
        {
            uint8_t counter = 0;
            while(!isConnected())
            {
                sprintf(g_buffer, "[%d] MPU9250::Magnitometer::wait(); awaitng for MPU...", counter);
                Serial.println(g_buffer);
                delay(1000);
            }
        }

        bool isConnected()
        {
            byte c = _bus.readByte(AK8963_ADDRESS, AK8963_WHO_AM_I);
            if (true)
            {
                Serial.print("AK8963 WHO AM I = ");
                Serial.println(c, HEX);
            }
            if (c == AK8963_WHOAMI_DEFAULT_VALUE)
            {
                Serial.print("MPU9250::Magnitometer::isConnected(); MPU is connected; AK8963_WHO_AM_I=");
                Serial.println(c, HEX);
            }
            else
            {
                Serial.print("MPU9250::Magnitometer::isConnected(); MPU is NOT connected; AK8963_WHO_AM_I=");
                Serial.println(c, HEX);
            }
            return (c == AK8963_WHOAMI_DEFAULT_VALUE);
        }

        void read(int16_t* destination)
        {
            _bus.writeByte(AK8963_ADDRESS, AK8963_CNTL, 0x11); // Start easurement

            uint8_t cntl, st1;
#ifdef LOG_M_READ
            if (1)
            {
                cntl = _bus.readByte(AK8963_ADDRESS, AK8963_CNTL);
                Serial.print("CNTL:"); Serial.println(cntl, BIN);
            }
#endif

            st1 = _bus.readByte(AK8963_ADDRESS, AK8963_ST1);
            while( !(st1 & 0x01) ) 
            { // Wait for ST1.DRDY             
                delay(5);
                st1 = _bus.readByte(AK8963_ADDRESS, AK8963_ST1);
            }

            uint8_t raw[6+1]; // + ST2 to reset ST1.DRDY
            _bus.readBytes(AK8963_ADDRESS, AK8963_XOUT_L, 7, &raw[0]);
            destination[0] = ((int16_t)raw[1] << 8) | (int16_t)raw[0];
            destination[1] = ((int16_t)raw[3] << 8) | (int16_t)raw[2];
            destination[2] = ((int16_t)raw[5] << 8) | (int16_t)raw[4];

#ifdef LOG_M_READ
            if (1)
            {
                Serial.print("XOUT_L:"); Serial.println(raw[0], BIN);
                Serial.print("XOUT_H:"); Serial.println(raw[1], BIN);
                Serial.print("YOUT_L:"); Serial.println(raw[2], BIN);
                Serial.print("YOUT_H:"); Serial.println(raw[3], BIN);
                Serial.print("ZOUT_L:"); Serial.println(raw[4], BIN);
                Serial.print("ZOUT_H:"); Serial.println(raw[5], BIN);
                Serial.print("ST2:"); Serial.println(raw[6], BIN);

                st1 = _bus.readByte(AK8963_ADDRESS, AK8963_ST1);
                Serial.print("ST1:"); Serial.println(st1, BIN);

                cntl = _bus.readByte(AK8963_ADDRESS, AK8963_CNTL);
                Serial.print("CNTL:"); Serial.println(cntl, BIN);
            }
#endif
        }

        void update(Point& value)
        {
            read(_registers); // INT cleared on any read

            value.x = _registers[0];
            value.y = _registers[1];
            value.z = _registers[2];
            value.x *= _resolution;
            value.y *= _resolution;
            value.z *= _resolution;

#ifdef M_LOGGER_ENABLE
            log(value);
#endif
        }

        void print(const Point& value) const
        {
            char szX[15];
            char szY[15];
            char szZ[15];
            char* result_x = dtostrf_ex(value.x, 8, 2, szX);
            char* result_y = dtostrf_ex(value.y, 8, 2, szY);
            char* result_z = dtostrf_ex(value.z, 8, 2, szZ);
            sprintf(g_buffer,"{m:{x:%s, y:%s, z:%s}}", result_x, result_y, result_z);
            Serial.println(g_buffer);
        }

    private:
#ifdef M_LOGGER_ENABLE
        void log(const Point& value) const
        {
            char szX[20];
            char szY[20];
            char szZ[20];
            dtostrf(value.x, 11, 4, szX);
            dtostrf(value.y, 11, 4, szY);
            dtostrf(value.z, 11, 4, szZ);
            sprintf(g_buffer, "Magnitometer(%s, %s, %s)", szX, szY, szZ);
            Serial.println(g_buffer);
        }
#endif

        float resolution(const MAG_OUTPUT_BITS mag_output_bits) const
        {
            switch (mag_output_bits)
            {
                // Possible magnetometer scales (and their register bit settings) are:
                // 14 bit resolution (0) and 16 bit resolution (1)
                // Proper scale to return milliGauss
                case MAG_OUTPUT_BITS::_14BITS:
                    return 10. * 4912. / 8190.0;
                case MAG_OUTPUT_BITS::_16BITS:
                    return 10. * 4912. / 32760.0;
                default:
                    return 0.;
            }
        }
    };

public:
    Bus&          _bus;
#ifdef MPU_T_UPDATE
    Temperature   _t;
#endif
#ifdef MPU_G_UPDATE
    Gyroscope     _g;
#endif
#ifdef MPU_A_UPDATE
    Accelerometer _a;
#endif
#ifdef MPU_M_UPDATE
    Magnitometer  _m;
#endif
};
