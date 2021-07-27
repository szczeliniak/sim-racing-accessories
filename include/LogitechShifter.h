#ifndef LOGITECH_SHITER_H
#define LOGITECH_SHITER_H

#include <Joystick.h>
#include "Controller.h"

#define HS_XAXIS_12 400
#define HS_XAXIS_56 600
#define HS_YAXIS_135 800
#define HS_YAXIS_246 300

#define DI_REVERSE 1
#define DI_MODE 3

class LogitechShifter : public Controller
{

private:
    Joystick_ *joystick;
    uint8_t axisX;
    uint8_t axisY;
    uint8_t reverseButtonPin;
    int b[16];
    int gear = 0;
    int gearFirstButton = 1;
    int gearSecondButton = 2;
    int gearThirdButton = 3;
    int gearFourthButton = 4;
    int gearFifthButton = 5;
    int gearSixthButton = 6;
    int gearReverseButton = 7;
    int lastButtonState = 0;

    void desactivar();

public:
    LogitechShifter(Joystick_ *joystick, uint8_t axisX, uint8_t axisY, uint8_t reverseButtonPin, int gearFirstButton, int gearSecondButton, int gearThirdButton, int gearFourthButton, int gearFifthButton, int gearSixthButton, int gearReverseButton);
    void setup();
    void loop();
};

#endif