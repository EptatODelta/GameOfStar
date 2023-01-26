#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <sys/ioctl.h>
#include <math.h>

#include "output.h"
#include "types.h"
#include "conctrl.h"
#include "coninput.h"
#include "strutil.h"
#include "threadproc.h"
#include "progSE.h"
#include "datautil.h"

//OUTNUM__FLOAT_PERIOD OUTNUM__IS_FLOAT OUTNUM__BASE_OUTPUT_TYPE OUTNUM__BASE_OUTPUT OUTNUM__FORMATTING OUTNUM__POST_BASE11 OUTNUM__UNSIGNED OUTNUM__SCIENTIFIC_NOTATION

//---------Working Memory Processing---------




	
char programState = 0, KBinput = 0;
Position CursorPos = (Position){1,1};
long long runTime = 0;
struct winsize ConSize;
struct Size WindowSize;



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
	//---Starting-Procedures---
	
	atStart(InputThread, TimeThread, InputThreadAttr, TimeThreadAttr, InputThreadProcedure, TimeThreadProcedure);
	
	//-----------Body----------
	
start:
	FILE* newFile = F_open("test.boi", "r+b");
	char* Fb;
	Fb = F_createBuffer(newFile);
	OutStr(Fb);
	F_close(newFile);


	
	switch(programState) {
		default: {
			//system("clear");
			atEnd(0);
		}
	}
}





