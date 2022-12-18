#include "types.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

//-----Cursor Controls-----
void moveCursor(short X, int Y, Byte isRel, Position CursorPos) {
	if (isRel == 0) { printf("\e[%d;%dH", Y, X); }
	if (isRel == 1) { printf("\e[%d;%dH", Y+CursorPos.Y, X+CursorPos.X); }
}
void hideCursor() { printf("\e[?25l"); }
void showCursor() { printf("\e[?25h"); }


//-----Text Formatting-----
void setColor(Byte Color, Byte isBGColor, Byte isBold, Byte isUnderlined, Byte isHighInten) {
	printf("\e[%d;%dm", isBold+(isUnderlined*4), (Color+30)+(isBGColor*10)+(isHighInten*60));
}void resetColor() {
	printf("\e[0m");
}



//----Termios Console Modes----
void switchModes(struct termios* A) {
	tcsetattr(STDIN_FILENO, TCSANOW, A);
}
void getCurConMode(struct termios* A) {
	tcgetattr(STDIN_FILENO, A);
}
void changeModeFlags(struct termios* A, Byte flags) {
	(*A).c_lflag &= flags;
}



void func() {
	printf("%d", programState);
}

