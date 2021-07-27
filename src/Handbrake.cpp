#include "Handbrake.h"

Handbrake::Handbrake(Joystick_ *joystick, uint8_t pin) : pin(pin)
{
    this->joystick = joystick;
}

void Handbrake::setup()
{
    pinMode(pin, INPUT);
    joystick->begin();
}

void Handbrake::loop()
{
    int pot = analogRead(pin);
    int mapped = map(pot, 0, 1023, 0, 255);
    {
        joystick->setBrake(mapped);
    }
}