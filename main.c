#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>


#include "types.h"
#include "conctrl.h"
#include "input.h"

//---------Working Memory Processing---------

float mem[16];
void resetMem(float mem[16])
{
	for(int i = 0; i < 16; i++) mem[i]=0;
	return;
}

char programState = 1, KBinput = 0;
Position CursorPos = (Position){1,1};


//---------Utilities----------

void stopProgram(int exitCode, struct termios* oldt) {
	switchModes(oldt);
	resetColor();
	showCursor();
	putchar('\n');
	exit(exitCode);
}
void startProgram(struct termios* oldt, struct termios* newt) {
	getCurConMode(oldt);
	newt = oldt;
	changeModeFlags(newt, ~(ICANON | ECHO));
	switchModes(newt);

	system("clear");
	hideCursor();

	programState = 1;
	resetMem(mem);

	srand(time(NULL));

}


void* InputThreadProcedure(void* arg)
{
	while(1) {
		KBinput = getch();
	}
}


//---Processes-Prototypes---
short Menu();
//-----Main-----

int main (int argc, char *argv[])
{
	//--------Variables--------
	static struct termios oldt, newt;


	pthread_t InputThread;
	pthread_attr_t InputThreadAttr;
	pthread_attr_init (&InputThreadAttr);
	pthread_create(&InputThread, &InputThreadAttr, InputThreadProcedure, NULL);

	//---Starting-Procedures---
	startProgram(&oldt, &newt);



	//-----------Body----------
Selecting:
	while(programState==1) {
		switch(KBinput) {
			case 2: {printf("Hello World"); break;}
			case 3: {setColor((int)mem[0],0,1,0,1); break;}
			case 27:{if((int)mem[0] == 0) mem[0] = 7; else mem[0]--; printf("%d",(int)mem[0]); break;}
			case 30:{if((int)mem[0] == 7) mem[0] = 0; else mem[0]++; printf("%d",(int)mem[0]); break;}
			case 53:{programState = 0; break;}
			case 0: break;
			default:break;
		} KBinput = 0;
		fflush(stdout);
	}

Mode1:
	while(programState==2) {

	}
	
	resetMem(mem);
	switch(programState) {
		case 0: stopProgram(0, &oldt);
		case 1: goto Selecting;
		case 2: goto Mode1;
	}
}


short Menu() {
	
}




