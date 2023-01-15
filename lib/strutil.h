#ifndef STRUTIL_H_
#define STRUTIL_H_



short strLen(const char*);
short strMaxWordLen(const char*);
void strRes(char*);
void strInit(char*, const short);

void strFill(char*, const char);
void strFillTo(char*, const char, const short);
void strFillPartRel(char*, const char, const short, const short);
void strFillPart(char*, const char, const short, const short);

int strCopy(const char*, char*);
signed int strCompLen(const char*, const char*);

void strDecr(char*, short);
void strDecr1(char*);

short strFindChFirst(char*, const char);
short strFindChLast(char*, const char);

void strShift(char*, const short);
void strRotate(char*);

void strReplaceChars(char*, const char, const char);
void strReplaceMapping(char*, const char*);

unsigned long strHash(const char*);

void strFillRand(char*);

char Invert(const char in);



#endif
