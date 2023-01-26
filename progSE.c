#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#include "types.h"
#include "conctrl.h"


void atEnd(int exitCode) {

	resetColor();
	showCursor();
	putchar('\n');
	exit(exitCode);
}
void atStart(pthread_t InputThread, pthread_t TimeThread, pthread_attr_t InputThreadAttr, pthread_attr_t TimeThreadAttr, void* (*InputThreadProcedure)(void*), void* (*TimeThreadProcedure)(void*)) {
	
	system("clear");
	hideCursor();

	
	srand(time(NULL));
	pthread_create(&InputThread, &InputThreadAttr, InputThreadProcedure, NULL);
	pthread_create(&TimeThread, &TimeThreadAttr, TimeThreadProcedure, NULL);
}