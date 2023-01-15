#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <unistd.h>

#include "types.h"

void OutChar(const char);
void OutChars(const char, const short);
void OutNum(const long long int, const Byte, const Byte, const double);
void OutStr(const char*);
void OutStrLim(const char*, const short);
void OutText(const char*, const short, const short, const Byte);

#endif