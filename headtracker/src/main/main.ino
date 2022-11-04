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
}

void loop()
{
    lights.shift();

    static bool initMpu = true;
    if(initMpu)
    {
        //initMpu = false;
        Serial.println("AAAAAAAAAAAAAAAAAAAAAA.4");
        mpu.setup();
    }

    mpu.update();

    if (true) {
        char buffer[50];
        sprintf(buffer, "[%d] Hello world!", counter);
        Serial.println(buffer);
        ++counter;
    }

    delay(3000);

    //Types::printSizeof();
}
