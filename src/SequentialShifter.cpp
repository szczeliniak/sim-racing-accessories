#include "SequentialShifter.h"

SequentialShifter::SequentialShifter(Joystick_* joystick, uint8_t upButtonPin, uint8_t downButtonPin, int gearUpButton, int gearDownButton) : upButtonPin(upButtonPin), downButtonPin(downButtonPin), gearUpButton(gearUpButton), gearDownButton(gearDownButton)
{
    this->joystick = joystick;
}

void SequentialShifter::setup()
{
    pinMode(upButtonPin, INPUT_PULLUP);
    pinMode(downButtonPin, INPUT_PULLUP);
};

void SequentialShifter::loop()
{

    upValue = digitalRead(upButtonPin);
    downValue = digitalRead(downButtonPin);

    joystick->setButton(gearUpButton, !upValue);
    joystick->setButton(gearDownButton, !downValue);
};