#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <BleGamepad.h>

#define LH 15
#define LV 16
#define RH 4
#define RV 5

extern int leftXCenter;
extern int leftYCenter;
extern int rightXCenter;
extern int rightYCenter;

const int joystickCenter = 2047;
const int deadZone = 30;

void setupJoysticks();
void calibrateJoysticks();
void updateJoysticks(BleGamepad& bleGamepad);
int calibrateValue(int value, int center);

#endif
