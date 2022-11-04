#pragma once

class Led
{
public:
    Led(uint8_t pin, bool on = false)
        : _pin(pin)
        , _on(on)
    {
    }
 
    void setup()
    {
        pinMode(_pin, OUTPUT);
        write();
    }
 
    bool isOn() const
    {
        return _on;      
    }

    bool isOff() const
    {
        return !_on;
    }
  
    void set(bool on)
    {
        _on = on;
        write();
    }
  
    void setOn()
    {
        _on = true;
        write();
    }
  
    void setOff()
    {
        _on = false;
        write();
    }  
 
    bool toggle()
    {
        _on = !_on;
        write();
        return _on;
    }

private:
    uint8_t _pin;
    bool    _on;
    void write()
    {
        digitalWrite(_pin, _on ? HIGH : LOW); 
    }
};
