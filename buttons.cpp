#include "buttons.h"
#include <Arduino.h>

void setupButtons() {
  pinMode(LS, INPUT_PULLUP);
  pinMode(RS, INPUT_PULLUP);
  pinMode(CROSS, INPUT_PULLUP);
  pinMode(CIRCLE, INPUT_PULLUP);
}

void updateButtons(BleGamepad& bleGamepad) {
  if (digitalRead(LS) == LOW) {
    bleGamepad.press(BUTTON_11);
  } else {
    bleGamepad.release(BUTTON_11);
  }

  if (digitalRead(RS) == LOW) {
    bleGamepad.press(BUTTON_12);
  } else {
    bleGamepad.release(BUTTON_12);
  }

  if (digitalRead(CROSS) == LOW) {
    bleGamepad.press(BUTTON_1);
  } else {
    bleGamepad.release(BUTTON_1);
  }

  if (digitalRead(CIRCLE) == LOW) {
    bleGamepad.press(BUTTON_2);
  } else {
    bleGamepad.release(BUTTON_2);
  }
}
