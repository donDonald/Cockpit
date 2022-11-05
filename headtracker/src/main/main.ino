#include <Wire.h>
#include "Types.h"
#include "Lights.h"
#include "MPU9250.h"

uint8_t counter = 0;
Lights lights;
MPU9250 mpu;

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    lights.setup();
#if 1
    Serial.println("SETUP");
    mpu.setup();
#endif
}

void loop()
{
    lights.shift();

#if 0
    static bool initMpu = true;
    if(initMpu)
    {
        initMpu = false;
        Serial.println("SETUP AAAAAAAAAAAAAAAAAAAAAA");
        mpu.setup();
    }
#endif

    if (true) {
        static uint8_t counter = 0;
        char buffer[50];
        sprintf(buffer, "UPDATING[%d]", ++counter);        
        Serial.println(buffer);
    }
    mpu.update();

    delay(3000);

    //Types::printSizeof();
}
