#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <unistd.h>

#include "types.h"

void OutChar(const char);
void OutNum(const int);
void OutStr(const char*);
void OutStrLim(const char*, const short);

#endif