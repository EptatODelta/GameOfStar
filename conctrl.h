#ifndef CONCTRL_H_
#define CONCTRL_H_

#include "types.h"
#include <termios.h>
#include <stdio.h>

//cursor controls
void moveCursor(short, int, Byte, Position);
void hideCursor();
void showCursor();


//text formatting
void setColor(Byte, Byte, Byte, Byte, Byte);
void resetColor();


//termios console modes
void switchModes(struct termios*);
void getCurConMode(struct termios*);
void changeModeFlags(struct termios*, Byte);

void func();


#endif
