#include "joystick.h"
#include <Arduino.h>

int leftXCenter;
int leftYCenter;
int rightXCenter;
int rightYCenter;

void setupJoysticks() {
  pinMode(LH, INPUT);
  pinMode(LV, INPUT);
  pinMode(RH, INPUT);
  pinMode(RV, INPUT);
}

void calibrateJoysticks() {
  long leftXSum = 0;
  long leftYSum = 0;
  long rightXSum = 0;
  long rightYSum = 0;
  const int numSamples = 100;

  for (int i = 0; i < numSamples; i++) {
    leftXSum += analogRead(LH);
    leftYSum += analogRead(LV);
    rightXSum += analogRead(RH);
    rightYSum += analogRead(RV);
    delay(10);
  }

  leftXCenter = leftXSum / numSamples;
  leftYCenter = leftYSum / numSamples;
  rightXCenter = rightXSum / numSamples;
  rightYCenter = rightYSum / numSamples;

  Serial.print("Calibrated leftXCenter = ");
  Serial.println(leftXCenter);
  Serial.print("Calibrated leftYCenter = ");
  Serial.println(leftYCenter);
  Serial.print("Calibrated rightXCenter = ");
  Serial.println(rightXCenter);
  Serial.print("Calibrated rightYCenter = ");
  Serial.println(rightYCenter);
}

int calibrateValue(int value, int center) {
  if (value >= (center - deadZone) && value <= (center + deadZone)) {
    return joystickCenter;
  }
  return value;
}

void updateJoysticks(BleGamepad& bleGamepad) {
  int leftXValue = analogRead(LH);
  int leftYValue = analogRead(LV);
  int rightXValue = analogRead(RH);
  int rightYValue = analogRead(RV);

  leftXValue = calibrateValue(leftXValue, leftXCenter);
  leftYValue = calibrateValue(leftYValue, leftYCenter);
  rightXValue = calibrateValue(rightXValue, rightXCenter);
  rightYValue = calibrateValue(rightYValue, rightYCenter);

  int mappedLeftXValue = map(leftXValue, 0, 4095, 0, 32767);
  int mappedLeftYValue = map(leftYValue, 0, 4095, 0, 32767);
  int mappedRightXValue = map(rightXValue, 0, 4095, 0, 32767);
  int mappedRightYValue = map(rightYValue, 0, 4095, 0, 32767);

  bleGamepad.setLeftThumb(mappedLeftXValue, mappedLeftYValue);
  bleGamepad.setRightThumb(mappedRightXValue);
  bleGamepad.setLeftTrigger(mappedRightYValue);
}
