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

#define FALSE 0
#define TRUE  1
#define Null  0

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

#define StringCreate(a,b) char a[b]

#define OUTNUM__UNSIGNED		  1
#define OUTNUM__POST_BASE11		  2
#define OUTNUM__FORMATTING		  4
#define OUTNUM__BASE_OUTPUT		  8
#define OUTNUM__BASE_OUTPUT_TYPE 16
#define OUTNUM__IS_FLOAT		 32
#define OUTNUM__FLOAT_PERIOD	 64

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

typedef void*  			  Func;
typedef double 			M_Func;
typedef long long int	I_Func;
typedef char   			C_Func;
typedef char*  			S_Func;
typedef unsigned char 	B_Func;

typedef char 					 INT_8;
typedef short 					 INT_16;
typedef int 					 INT_32;
typedef long long int 			 INT_64;
typedef unsigned char 			UINT_8;
typedef unsigned short 			UINT_16;
typedef unsigned int 			UINT_32;
typedef unsigned long long int 	UINT_64;

typedef float  FINT_32;
typedef double FINT_64;


//-----unions------

typedef union Variable {
	unsigned int uINT32;
	int INT32;
	unsigned short uSHORT16;
	short SHORT16;
	unsigned long long int uLONG64;
	long long int LONG64;

	unsigned char uBYTE8;
	char BYTE8;

	void* POINTER;

	float FLOAT32;
	double FLOAT64;

	long long int key[2];
} let;
typedef let HTable;




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
