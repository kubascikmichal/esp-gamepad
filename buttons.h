#ifndef BUTTONS_H
#define BUTTONS_H

#include <BleGamepad.h>

#define LS 17
#define RS 6
#define CROSS 39
#define CIRCLE 38

void setupButtons();
void updateButtons(BleGamepad& bleGamepad);

#endif
