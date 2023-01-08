#ifndef STRUTIL_H_
#define STRUTIL_H_

short strLen(const char*);
void strRes(char*);
void strInit(char*, const short);
void strFill(char*, const char);
void strFillTo(char*, const char, const short);
int strCopy(const char*, char*);
signed int strCompLen(const char*, const char*);
void strDecr(char*, short);
void strDecr1(char*);

void strFindChFirst(char*, const char);
void strFindChLast(char*, const char);
void strShift(char*, const short);
void strRotate(char*);

char Invert(const char in);

#endif
