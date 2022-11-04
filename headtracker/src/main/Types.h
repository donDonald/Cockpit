#pragma once

class Types
{
public:
    static void printSizeof()
    {
        char buffer[50];

        sprintf(buffer, "sizeof(void):%d", sizeof(void));
        Serial.println(buffer);

        sprintf(buffer, "sizeof(void*):%d", sizeof(void*));
        Serial.println(buffer);

        sprintf(buffer, "sizeof(char):%d", sizeof(char));
        Serial.println(buffer);

        sprintf(buffer, "sizeof(int):%d", sizeof(int));
        Serial.println(buffer);

        sprintf(buffer, "sizeof(long):%d", sizeof(long));
        Serial.println(buffer);

        sprintf(buffer, "sizeof(float):%d", sizeof(float));
        Serial.println(buffer);

        sprintf(buffer, "sizeof(bool):%d", sizeof(bool));
        Serial.println(buffer);
    }

//    static int sprintf(char *__s, const char *__fmt, ...)
//    {
//        char buffer[50];
//        return ::sprintf(buffer, __fmt);
//    }

};
