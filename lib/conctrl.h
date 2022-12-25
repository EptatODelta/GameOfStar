#ifndef CONCTRL_H_
#define CONCTRL_H_

#include <termios.h>
#include <stdio.h>

#include "types.h"

//cursor controls
void moveCursor(short, int, Byte, Position);
void hideCursor();
void showCursor();


//text formatting
void setColor(Byte, Byte, Byte, Byte, Byte);
void resetColor();


//termios console modes

void func();


#endif
