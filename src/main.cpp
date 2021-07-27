#include <Arduino.h>
#include "LogitechShifter.h"
#include "SequentialShifter.h"
#include "Handbrake.h"
#include "Joystick.h"

#define REPORT_ID 0x03

#define LOGITECH_SHIFTER_AXIS_X A0
#define LOGITECH_SHIFTER_AXIS_Y A2
#define LOGITECH_SHIFTER_REVERSE_BUTTON_PIN 2
#define LOGITECH_SHIFTER_GEAR_FIRST_BUTTON 1
#define LOGITECH_SHIFTER_GEAR_SECOND_BUTTON 2
#define LOGITECH_SHIFTER_GEAR_THIRD_BUTTON 3
#define LOGITECH_SHIFTER_GEAR_FOURTH_BUTTON 4
#define LOGITECH_SHIFTER_GEAR_FIFTH_BUTTON 5
#define LOGITECH_SHIFTER_GEAR_SIXTH_BUTTON 6
#define LOGITECH_SHIFTER_GEAR_REVERSE_BUTTON 7

#define SEQUENTIAL_SHIFTER_BUTTON_UP_PIN 8
#define SEQUENTIAL_SHIFTER_BUTTON_DOWN_PIN 7
#define SEQUENTIAL_SHIFTER_GEAR_UP_BUTTON 8
#define SEQUENTIAL_SHIFTER_GEAR_DOWN_BUTTON 9

#define HANDBRAKE_PIN A1

#define DELAY 10
#define NUMBER_OF_CONTROLLERS 3

Joystick_ *joystick;
Controller *controllers[NUMBER_OF_CONTROLLERS];

void setup()
{
  joystick = new Joystick_(REPORT_ID, JOYSTICK_TYPE_GAMEPAD, 9, 0, false, false, false, false, false, false, false, false, false, true, false);

  controllers[0] = new LogitechShifter(joystick, LOGITECH_SHIFTER_AXIS_X, LOGITECH_SHIFTER_AXIS_Y, LOGITECH_SHIFTER_REVERSE_BUTTON_PIN, 
                                      LOGITECH_SHIFTER_GEAR_FIRST_BUTTON, LOGITECH_SHIFTER_GEAR_SECOND_BUTTON, LOGITECH_SHIFTER_GEAR_THIRD_BUTTON, 
                                      LOGITECH_SHIFTER_GEAR_FOURTH_BUTTON, LOGITECH_SHIFTER_GEAR_FIFTH_BUTTON, LOGITECH_SHIFTER_GEAR_SIXTH_BUTTON, 
                                      LOGITECH_SHIFTER_GEAR_REVERSE_BUTTON);
  controllers[1] = new SequentialShifter(joystick, SEQUENTIAL_SHIFTER_BUTTON_UP_PIN, SEQUENTIAL_SHIFTER_BUTTON_DOWN_PIN, 
                                      SEQUENTIAL_SHIFTER_GEAR_UP_BUTTON, SEQUENTIAL_SHIFTER_GEAR_DOWN_BUTTON);
  controllers[2] = new Handbrake(joystick, HANDBRAKE_PIN);

  for (int i = 0; i < NUMBER_OF_CONTROLLERS; i++)
  {
    controllers[i]->setup();
  }

  joystick->begin();
}

void loop()
{
  for (int i = 0; i < NUMBER_OF_CONTROLLERS; i++)
  {
    controllers[i]->loop();
  }

  delay(DELAY);
}