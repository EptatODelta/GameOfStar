#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <sys/ioctl.h>

#include "output.h"
#include "types.h"
#include "conctrl.h"
#include "input.h"
#include "strutil.h"

//---------Working Memory Processing---------

void resetMem(float *mem)
{
	for(int i = 0; i < arraysMgm.mem1Len; i++) mem[i]=0;
	return;
}

char programState = 1, KBinput = 0;
Position CursorPos = (Position){1,1};
long long runTime = 0;
struct winsize ConSize;


ArraysList arraysMgm;


//---------Utilities-----------

void atEnd(int exitCode) {
	free(arraysMgm.mem1);
	free(arraysMgm.memStr);

	resetColor();
	showCursor();
	putchar('\n');
	exit(exitCode);
}
void atStart(pthread_t InputThread, pthread_t TimeThread, pthread_attr_t InputThreadAttr, pthread_attr_t TimeThreadAttr, void* (*InputThreadProcedure)(void*), void* (*TimeThreadProcedure)(void*)) {
	arraysMgm.mem1Len = 1024;
	arraysMgm.mem1 = (float*) malloc(arraysMgm.mem1Len * sizeof(float));
	arraysMgm.memStrLen = 4096;
	arraysMgm.memStr = (char*)malloc(arraysMgm.memStrLen * sizeof(char));

	system("clear");
	hideCursor();

	programState = 1;
	resetMem(arraysMgm.mem1);

	srand(time(NULL));
	pthread_create(&InputThread, &InputThreadAttr, InputThreadProcedure, NULL);
	pthread_create(&TimeThread, &TimeThreadAttr, TimeThreadProcedure, NULL);
}






//-------Threads--------

void* InputThreadProcedure(void* arg)
{	
	static struct termios oldt, newt;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	newt.c_cc[VMIN] = 1;
	newt.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);	

	while(programState!=0) {
		KBinput = getch();
		if(KBinput == 53) { programState = 0; break; }
	}

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	pthread_exit(NULL);
}
void* TimeThreadProcedure(void* arg)
{
	while(programState>0) {
		runTime = (long long)(clock() / CLOCKS_PER_SEC);
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &ConSize);
		arraysMgm.mem1[0] = (float)ConSize.ws_col, arraysMgm.mem1[1] = (float)ConSize.ws_row;
		usleep(500*1000);
	}
	pthread_exit(NULL);
}





//---Processes-Prototypes---
short Menu();
//-----Main-----

int main (int argc, char *argv[])
{
	//--------Variables--------

	pthread_t InputThread, TimeThread;
	pthread_attr_t InputThreadAttr, TimeThreadAttr;
	pthread_attr_init (&InputThreadAttr); pthread_attr_init (&TimeThreadAttr);

	String(Astring, 7) = "Hello!\0";
	String(OutString, 45) = "A string.\n\0";
	
	//---Starting-Procedures---
	
	atStart(InputThread, TimeThread, InputThreadAttr, TimeThreadAttr, InputThreadProcedure, TimeThreadProcedure);
	arraysMgm.mem1[2] = 1;

	//-----------Body----------
	
Menu:
	while(programState==1) {
		switch(KBinput) {
			case 1: break;
			default:break;
			case ESCAPE: break;
		} KBinput = 0;
		

		OutChar('\n');
		OutStrLines("ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\n\0", (short)arraysMgm.mem1[0], (short)arraysMgm.mem1[1]);

		
		fflush(stdout);

		usleep(83333);
		system("clear");
	}

Mode1:
	while(programState==2) {

	}
	
	resetMem(arraysMgm.mem1);
	switch(programState) {
		case 0: {
			system("clear");
			atEnd(0);
		}
		case 1: goto Menu;
		case 2: goto Mode1;
	}
}


short Menu() {
	
}




