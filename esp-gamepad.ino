#include <BleGamepad.h>
#include "joystick.h"
#include "buttons.h"

BleGamepad bleGamepad("ESP Controller", "Ziligang");

#define numOfButtons 16
#define numOfHatSwitches 0
#define enableX true
#define enableY true
#define enableZ true
#define enableRZ false
#define enableRX true
#define enableRY false
#define enableSlider1 false
#define enableSlider2 false

void setup() {
  setupJoysticks();
  setupButtons();

  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  
  BleGamepadConfiguration bleGamepadConfig;
  bleGamepadConfig.setWhichAxes(enableX, enableY, enableZ, enableRX, enableRY, enableRZ, enableSlider1, enableSlider2);
  bleGamepadConfig.setAxesMin(0);
  bleGamepadConfig.setAxesMax(32767);
  bleGamepad.begin(&bleGamepadConfig);

  calibrateJoysticks();
}

void loop() {
  if (bleGamepad.isConnected()) {
    updateJoysticks(bleGamepad);
    updateButtons(bleGamepad);

    // Send the gamepad report
    bleGamepad.sendReport();
    delay(1);
  }
}
