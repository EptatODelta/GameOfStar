#include <pthread.h>
#include <time.h>
#include <stdlib.h>

#include "types.h"
#include "conctrl.h"

void resetMem(float *mem)
{
	for(int i = 0; i < arraysMgm.mem1Len; i++) mem[i]=0;
	return;
}

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