#include "SequentialShifter.h"

SequentialShifter::SequentialShifter(uint8_t reportId, uint8_t up, uint8_t down) : up(up), down(down)
{
    joystick = new Joystick_(reportId, JOYSTICK_TYPE_GAMEPAD, 2, 0, false, false, false, false, false, false, false, false, false, false, false);
}

SequentialShifter::~SequentialShifter()
{
    delete joystick;
}

void SequentialShifter::setup()
{
    pinMode(up, INPUT_PULLUP);
    pinMode(down, INPUT_PULLUP);

    joystick->begin();
};

void SequentialShifter::loop()
{

    upValue = digitalRead(up);
    downValue = digitalRead(down);

    joystick->setButton(0, !upValue);
    joystick->setButton(1, !downValue);
};