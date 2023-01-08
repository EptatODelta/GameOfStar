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
#include "threadproc.h"
#include "progSE.h"

//---------Working Memory Processing---------



char programState = 1, KBinput = 0;
Position CursorPos = (Position){1,1};
long long runTime = 0;
struct winsize ConSize;


ArraysList arraysMgm;


//---------Utilities-----------



//---Processes-Prototypes---

//-----Main-----

int main (int argc, char *argv[])
{
	//--------Variables--------

//pthreads
	pthread_t InputThread, TimeThread;
	pthread_attr_t InputThreadAttr, TimeThreadAttr;
	pthread_attr_init (&InputThreadAttr); pthread_attr_init (&TimeThreadAttr);
//booleans
	
	
//strings
	char tempString[13] = "!dlroW olleH";

	//---Starting-Procedures---
	
	atStart(InputThread, TimeThread, InputThreadAttr, TimeThreadAttr, InputThreadProcedure, TimeThreadProcedure);
	arraysMgm.mem1[2] = 1;

	//-----------Body----------
	
Menu:
	while(programState==1) {
		switch(KBinput) {
			case 1: break;
			case 27:strRotate(tempString); break;
			default:break;
			case ESCAPE: break;
		} KBinput = 0;
		
		fflush(stdout);

		OutStr(tempString);

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





