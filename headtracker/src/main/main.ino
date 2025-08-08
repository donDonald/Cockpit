#include "Types.h"
#include "Lights.h"
#include "MPU9250.h"

uint8_t counter = 0;
Lights lights;
Bus bus(MPU9250_DEFAULT_ADDRESS);
MPU9250 mpu(bus);

void setup()
{
    Serial.begin(9600);
    while (!Serial); // Wait for Serial Monitor to connect
    bus.start();
    lights.setup();
    mpu.setup();
}

void loop()
{
    //Types::printSizeof();
    lights.shift();

#if 1
    if (false)
    {
        static uint8_t counter = 0;
        char buffer[50];
        sprintf(buffer, "UPDATING[%d]", ++counter);        
        Serial.println(buffer);
    }
    mpu.update();
#endif

    delay(3000);
}