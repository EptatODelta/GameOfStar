#ifndef TYPES_H_
#define TYPES_H_

#include <pthread.h>

//-----defines-----

#define BLACK 0
#define RED   1
#define GREEN 2
#define YELLO 3
#define BLUE  4
#define MAGEN 5
#define CYAN  6
#define WHITE 7






//-----structs-----

typedef struct Position {
	short X, Y;
} Position;
typedef struct Size {
	short X, Y;
} Size;



//----typedefs-----

typedef unsigned char Byte;
typedef unsigned char Mode;



//-----unions------






//------enums------



//-----externs-----
extern char programState, KBinput;
extern float mem[16];
extern Position CursorPos;
extern pthread_t InputThread;


#endif
