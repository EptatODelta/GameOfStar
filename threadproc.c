#include <termios.h>
#include <pthread.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>

#include "types.h"
#include "input.h"

extern void* InputThreadProcedure(void* arg)
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
extern void* TimeThreadProcedure(void* arg)
{
	while(programState>0) {
		runTime = (long long)(clock() / CLOCKS_PER_SEC);
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &ConSize);
		arraysMgm.mem1[0] = (float)ConSize.ws_col, arraysMgm.mem1[1] = (float)ConSize.ws_row;
		usleep(500*1000);
	}
	pthread_exit(NULL);
}