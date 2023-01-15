
#include "types.h"
#include <stdlib.h>


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

short strMaxWordLen(const char* string) {
	short length = strLen(string), wordMaxLength = 0, tempWordLength = 0;

    for(int i = 0; i < length; i++) {
        if(string[i] == ' ') {
            if(tempWordLength > wordMaxLength) { wordMaxLength = tempWordLength; } 
            tempWordLength = 0; continue; }
        else {
            tempWordLength++;
        }
    }
	if(tempWordLength > wordMaxLength) wordMaxLength = tempWordLength;

	return wordMaxLength;
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
		string[i] = ' ';
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
void strFillPartRel(char*string,const char val, const short start, const short length) {
	for(int i = start; i < length; i++) string[i] = val;
}
void strFillPart(char*string, const char val, const short start, const short end) {
	if(end <= start) return;
	strFillPartRel(string, val, start, end-start);
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
	
	for(int i = 0; i < length; i++) {
		tempStr[i] = string[length - i - 1];
	}
	strCopy(tempStr, string);
	return;
}


void strReplaceChars(char* string, const char toReplace, const char With) {
	int length = strLen(string);
	for(int i = 0; i < length; i++) {
		if(string[i] == toReplace) {
			string[i] = With;
    	}
	}
}
void strReplaceMapping(char* string, const char* mapping) {
	int length = strLen(string);
	for(int i = 0; i < length; i++) {
		string[i] = mapping[string[i]];
	}
}


unsigned long strHash(const char* str) {
	unsigned long hash = 5381;
	int c;
	while ((c = *str++)) {
		hash = ((hash << 5) + hash) + c;
	}
	return hash;
}

void strFillRand(char* string) {
	short len = strLen(string);
	for(int i = 0; i < len; i++) {
		string[i] = rand() % 95 + 32;
	} return;
}

char Invert(const char in) {
	if(in == 0) return 1;
	else return 0;
}
