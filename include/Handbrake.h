#ifndef HANDBRAKE_SHITER_H
#define HANDBRAKE_SHITER_H

#include <Joystick.h>
#include "Controller.h"

class Handbrake : public Controller
{

private:
    Joystick_ *joystick;
    uint8_t pin;

public:
    Handbrake(Joystick_ *joystick, uint8_t pin);
    void setup();
    void loop();
};

#endif