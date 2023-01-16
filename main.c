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
#include "coninput.h"
#include "strutil.h"
#include "threadproc.h"
#include "progSE.h"
#include "datautil.h"
#include "mathsutil.h"

//OUTNUM__FLOAT_PERIOD OUTNUM__IS_FLOAT OUTNUM__BASE_OUTPUT_TYPE OUTNUM__BASE_OUTPUT OUTNUM__FORMATTING OUTNUM__POST_BASE11 OUTNUM__UNSIGNED

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

//others
INT_64 a = 1; FINT_64 b = 0.6;
	//---Starting-Procedures---
	
	atStart(InputThread, TimeThread, InputThreadAttr, TimeThreadAttr, InputThreadProcedure, TimeThreadProcedure);
	arraysMgm.mem1[0] = 20;

	//-----------Body----------
	
Menu:
	while(programState==1) {
		switch(KBinput) {
			case 1: break;
			case 27: a--; break;
			case 30: a++; break;
			case 45: b-=0.05; break;
			case 31: b+=0.05; break;
			default:break;
			case ESCAPE: break;
		} KBinput = 0;

		for(int i = 0; i < 100; i++) {
			moveCursor(0+i, 15, 0, (Position){0,0});
			OutChar('-');
		}

		for(int i = 0; i < 30; i++) {
			moveCursor(50, 0+i, 0, (Position){0,0});
			OutChar('|');
		}
#include <math.h>
		for(int x = -50; x < 50; x++) {
			int y = a*sin(b*x);
			moveCursor(x+50, 15-(y), 0, (Position){0,0});
			OutChar('#');
		}

		fflush(stdout);

		usleep(83333);
		system("clear");
	}

	
	resetMem(arraysMgm.mem1);
	switch(programState) {
		case 0: {
			system("clear");
			atEnd(0);
		}
		case 1: goto Menu;
	}
}





