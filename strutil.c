#include "types.h"
#include <stdio.h>



short strLen(const char* string) {
	for(int i = 0; i < WORD_ULIMIT;)
	{
		switch(string[i]) {
			case'\0': return i;
			default:     break;
		}
		switch(string[i+1]) {
			case'\0': return i+1;
			default: i+=2; continue;
		}
	}
	return 0;
}

void strRes(char* string) {
	short len = strLen(string);
	for(int i = 0; i < len; i++) {
		string[i] = ' ';
	}
	string[len] = '\0';
}
void strInit(char* string, const short len) {
	for(int i = 0; i < len; i++) {
		string[i] = 'a';
	}
	string[len] = '\0';
}
void strFill(char* string, const char val) {
	short len = strLen(string);
	for(int i = 0; i < len; i++) {
		string[i] = val;
	}
}
void strFillTo(char* string, const char val, const short to) {
	for(int i = 0; i < to; i++) string[i] = val;
}

int strCopy(const char* stringFrom, char* stringTo) {
	short lenFrom = strLen(stringFrom), lenTo = strLen(stringTo);
	if(lenFrom > lenTo) return 5;
	for(int i = 0; i < lenFrom; i++) {
		stringTo[i] = stringFrom[i];
	}
}

signed int strCompLen(const char* stringA, const char* stringB) {
	for(int i = 0; i < WORD_ULIMIT; i++) {
		if(stringA[i] == '\0' && stringB[i] == '\0') return 0;
		else if (stringA[i] == '\0') return 1;
		else if (stringB[i] == '\0') return -1;
		else continue;
	}
	return 2;
}
void strDecr(char* string, short val) {
	short Len = strLen(string);
	string[Len - val] = '\0';
}
void strDecr1(char* string) {
	short Len = strLen(string);
	string[Len - 1] = '\0';
}

short strFindChFirst(char* string, const char val) {
	short Len = strLen(string);
	for(int i = 0; i < Len; i++) {
		if(string[i] == val) return i;
	}
	return -1;
}
short strFindChLast(char* string, const char val) {
	short Len = strLen(string);
	for(int i = Len; i >= 0; i--) {
		if(string[i] == val) return i;
	}
	return -1;
}

void strShift(char* string, int N) {
    int length = strLen(string);

    if(N == 0) return;
    else if(N < 0) {
        for(int i = 0; i < length; i++) {
          string[i] = string[-N + i];
        }
    } else {
        for(int i = length - N - 1; i >= 0; i--) {
          string[i + N] = string[i];
        }
		string[length] = 0;
    }
}
void strRotate(char* string) {
	const short length = strLen(string);

	char tempStr[length];
	strInit(tempStr, length);
	printf("a %d\n", length);
	
	for(int i = 0; i < length; i++) {
		tempStr[i] = string[length - i];
		printf("%d %d %s\t%s\n", i, (length-i), tempStr, string);
	}
	strCopy(tempStr, string);
	return;
}


char Invert(const char in) {
	if(in == 0) return 1;
	else return 0;
}
