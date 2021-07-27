#ifndef SEQUENTIAL_SHITER_H
#define SEQUENTIAL_SHITER_H

#include <Joystick.h>
#include "Controller.h"

class SequentialShifter : public Controller
{

private:
    Joystick_ *joystick;
    uint8_t upButtonPin;
    uint8_t downButtonPin;
    int upValue = 0;
    int downValue = 0;
    int gearUpButton = 1;
    int gearDownButton = 2;

public:
    SequentialShifter(Joystick_ *joystick, uint8_t upButtonPin, uint8_t downButtonPin, int gearUpButton, int gearDownButton);
    void setup();
    void loop();
};

#endif