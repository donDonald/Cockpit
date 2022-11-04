#pragma once

#include "Led.h"

class Lights
{
public:
    static constexpr uint8_t COUNT = 2;

    enum {
        RED = 0,
        YELLOW
    };

    Lights()
    {
    }

    void setup()
    {
        for(uint8_t i=0; i<COUNT; ++i) {
            _leds[i].setup();
        }
    }

    void shift()
    {
        static uint8_t counter = 0;
        uint8_t rem = counter % COUNT;
        ++counter;
        for(uint8_t i=0; i<COUNT; ++i) {
            _leds[i].setOff();
        }
        _leds[rem].setOn();
    }

    Led& red()
    {
        return _leds[RED];
    }

    Led& yellow()
    {
        return _leds[YELLOW];
    }

private:
    Led _leds[COUNT] = {{21}, {20}};
};