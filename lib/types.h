#ifndef TYPES_H_
#define TYPES_H_

#include <pthread.h>
#include <sys/ioctl.h>

//-----defines-----

#define BLACK 0
#define RED   1
#define GREEN 2
#define YELLO 3
#define BLUE  4
#define MAGEN 5
#define CYAN  6
#define WHITE 7

#define ESCAPE 53

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

#define String(a,b) char a[b]

#define BYTE_ULIMIT			   255
#define BYTE_SLIMIT			   127
#define BYTE_NSLIMIT	      -128
#define WORD_ULIMIT	     	 65535
#define WORD_SLIMIT			 32767
#define WORD_NSLIMIT		-32768
#define DWORD_ULIMIT	4294967295
#define DWORD_SLIMIT	2147483647
#define DWORD_NSLIMIT  -2147483648
#define QWORD_ULIMIT  1.8446744e19
#define QWORD_SLIMIT   9.223372e18
#define QWORD_NSLIMIT -9.223372e18

//-----structs-----

typedef struct Position {
	short X, Y;
} Position;
typedef struct Size {
	short X, Y;
} Size;
typedef struct Arrays {
	float* mem1;
	int mem1Len;
	char* memStr;
	int memStrLen;
} ArraysList;



//----typedefs-----

typedef unsigned char Byte;
typedef unsigned char Mode;


//-----unions------






//------enums------



//-----externs-----
extern char programState, KBinput;
extern Position CursorPos;
extern pthread_t InputThread;
extern pthread_t TimeThread;
extern long long runTime;
extern ArraysList arraysMgm;
extern struct winsize ConSize;

#endif
