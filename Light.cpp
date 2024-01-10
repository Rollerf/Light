#include "Light.h"
#include "Arduino.h"
#include "Timer.h"

TON *tLightOn;

Light::Light(unsigned char pin)
{
    _pin = pin;
}

void Light::begin()
{
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, HIGH);
    _state = false;
    _automatic = false;
    tLightOn = new TON(240000);
}

void Light::turnOn()
{
    _state = true;
    digitalWrite(_pin, LOW);
}

void Light::turnOnWithTimer()
{
    _state = true;
    digitalWrite(_pin, LOW);
    tLightOn->IN(true);
}

void Light::turnOff()
{
    _state = false;
    digitalWrite(_pin, HIGH);
}

bool Light::getState()
{
    return _state;
}

void Light::turnOnAutomatic()
{
    _automatic = true;
}

void Light::turnOffAutomatic()
{
    _automatic = false;
}

bool Light::isAutomatic()
{
    return _automatic;
}

bool Light::isOn()
{
    return _state;
}

void Light::manageLightState()
{
    if (_automatic && tLightOn->IN(true))
    {
        turnOff();
        tLightOn->IN(false);
    }
}

void Light::manageLightStateWithExternalCondition(bool externalCondition)
{
    if (_automatic && externalCondition)
    {
        return turnOn();
    }

    return turnOff();
}