
#video


# Arduino IDE
https://amperka.ru/page/arduino-ide
https://github.com/arduino/arduino-ide/releases/

```
$ wget https://github.com/arduino/arduino-ide/releases/download/2.0.0/arduino-ide_2.0.0_Linux_64bit.zip
$ unzip ./arduino-ide_2.0.0_Linux_64bit.zip
```


avrdude: ser_open(): can't open device "/dev/ttyACM0": Permission denied
Failed uploading: uploading error: exit status 1
```
$ sudo usermod -a -G dialout $USER
````
After this, reboot your device and open Arduino IDE.

# Подключение Акселерометра и Магнитометра (via I2C - SCL/SDA )
10-ти осевой модуль датчика отслеживания CJMCU MPU9250 10DOF

{
    https://www.youtube.com/watch?v=gGNUtTtGCj0  (1:41:??) - Подключение акселерометра
    last = 1:47:??;
}

Либа на гитхабе для этого чипа: (https://github.com/hideakitai/MPU9250.git)[https://github.com/hideakitai/MPU9250]

Ещё либа на гитхабе для этого чипа: (https://github.com/kriswiner/MPU9250.git)[https://github.com/kriswiner/MPU9250/]

https://compacttool.ru/10-ti-osevoj-modul-datchika-otslezhivaniya-cjmcu-mpu9250-10dof
Here is a dedicated library for MPU9250 https://www.arduino.cc/reference/en/libraries/mpu9250/

MPU9250 {
    The MPU-9250 is comprised of the following key blocks and functions:
    Three-axis MEMS rate gyroscope sensor with 16-bit ADCs and signal conditioning
    Three-axis MEMS accelerometer sensor with 16-bit ADCs and signal conditioning
    Three-axis MEMS magnetometer sensor with 16-bit ADCs and signal conditioning
    Digital Motion Processor (DMP) engine
    Primary I 2 C and SPI serial communications interfaces
    Auxiliary I 2 C serial interface for 3 rd party sensors
    Clocking
    Sensor Data Registers
    FIFO: 512-byte FIFO register that is accessible via the Serial Interface.
    Interrupts
    Digital-Output Temperature Sensor: An on-chip temperature sensor and ADC are used to measure the MPU-9250 die temperature. The readings from the ADC can be read from the FIFO or the Sensor Data registers.
    Gyroscope, Accelerometer and Magnetometer Self-test: [r13, r16]
    Bias and LDO: The bias and LDO section generates the internal supply and the reference voltages and currents required by the MPU-9250.
    Charge Pump: An on-chip charge pump generates the high voltage required for the MEMS oscillators.
}









## References
* (X-plane 11 | P3D | DCS world | WarThunder | 5ти осевой трекер за 1000 рублей | июнь 2020)[https://www.youtube.com/watch?v=RhbhPYj6SKo]
* (Как сделать Инерционный трекер для Гонок и не только.......)[https://www.youtube.com/watch?v=hKkj5Z_FWKo]
* (Инерционный трекер на базе Arduino и GY-85 + Xbee pro S1)[https://www.youtube.com/watch?v=HkD17MWOSjs]



Простой, дешевый и достаточно точный трекер на 5ть (честных) осей, на базе Arduino nano, с себестоимостью от 1000 рублей (на июнь 2020 года), по описанию проекта Razor AHRS 5DOF для Opentrack. Настройка для основных симуляторов. Мое сравнение с аналогами.

Запчасти:
 * Arduino Nano V3

https://roboshop.spb.ru/arduino/kontrollery-arduino/arduino-nano-v3

 * GY-9250/MPU-9250 (9-осевой датчик 3D положения, гироскоп, акселерометр, магнитометр)
     * (10-ти осевой модуль датчика отслеживания CJMCU MPU9250 10DOF)[https://www.chipdip.ru/product0/8010864439]
    
 * GY-521/MPU 6050 (3-х осевой гироскоп и акселерометр)
     *(Гироскоп GY-521 чип MPU-6050)[https://www.chipdip.ru/product0/8009337879]

 * Разъём PLS-4 (Папа)
 * Разъём BLS-4 (Мама)



https://roboshop.spb.ru/arduino/Ardui...
https://duino.ru/mpu9250-giroskop-aks...

RAZOR (конструкция и настройка трекера)
https://www.sites.google.com/site/diy...

Программа (среда) для прошивки Arduino (IDE версии) 
https://www.arduino.cc/en/Main/Software#

Программа OpenTrack
https://github.com/opentrack/opentrac...



Arduino joystick
{
    {
        # Видео как сделать что-бы ардуинка понималась виндой как джойстик
        # Там используется Gamepad из https://www.arduino.cc/reference/en/libraries/hid-project/
        https://www.youtube.com/watch?v=Wb2YhZVQl_4&t=1210s

        https://github.com/NicoHood/HID
        {
            Supported HID devices:

                Keyboard with Leds out (8 modifiers + 6 keys pressed at the same time, + 1 limited linux consumer key)
                Teensy Keyboard with different keyboard layouts (german, french and many more) soon
                NKRO Keyboard with Leds out (press up to 113 keys at the same time)
                Mouse (5 buttons, move, wheel)
                BootKeyboard/BootMouse BIOS protocol support
                Absolute Mouse
                Consumer/Media Keys (4 keys for music player, web browser and more)
                System Key (for PC standby/shutdown)
                Gamepad (32 buttons, 4 16bit axis, 2 8bit axis, 2 D-Pads)
                RawHID
                SurfaceDial
                Each device is available as single or multi report device (except RawHID)

            See the wiki for more information about features etc.
        }
    }

    {
        Ещё одна либа которая так  и называется Joystick
        https://github.com/MHeironimus/ArduinoJoystickLibrary/tree/version-2.0
        {
            The joystick or gamepad can have the following features:

                Buttons (default: 32)
                Up to 2 Hat Switches
                X, Y, and/or Z Axis (up to 16-bit precision)
                X, Y, and/or Z Axis Rotation (up to 16-bit precision)
                Rudder (up to 16-bit precision)
                Throttle (up to 16-bit precision)
                Accelerator (up to 16-bit precision)
                Brake (up to 16-bit precision)
                Steering (up to 16-bit precision)
        }
    }

    {
        https://www.youtube.com/watch?v=XyYUTsFYSFU
    }

    {
        Тут чувак использует ту-же ArduinoJoystickLibrary для своего РУСа
        https://www.youtube.com/watch?v=XcKmBWGFUn8
    }

    {
        Тут тоже пользуют ArduinoJoystickLibrary для своего РУСа
        https://www.youtube.com/watch?v=wkY1NsbWj5I

    }

}

