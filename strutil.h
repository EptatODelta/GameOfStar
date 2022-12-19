#ifndef STRUTIL_H_
#define STRUTIL_H_

short strLen(const char*);
void strRes(char*);
void strFill(char*, const char);
void strCopy(const char*, char*);
signed int strCompLen(const char*, const char*);
void strDecr(char*, short);
void strDecr1(char*);

char Invert(const char in);

#endif
