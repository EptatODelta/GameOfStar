#include <stdio.h>
#include <math.h>

#include "types.h"

char ChToSmall(char Input) {
	if((Input >= 'A') && (Input <= 'Z'))
	{
		return (Input+32);
	}
	else return Input;
}
char ChToCapitalized(char Input) {
	if((Input >= 'a') && (Input <= 'Z'))
	{
		return (Input-32);
	}
	else return Input;
}


unsigned char getch() {
	Byte In = ChToSmall(getchar()), Out = 0;

	switch(In){
		case ' ': Out = 0; break;
		case '1': Out = 1; break;
		case '2': Out = 2; break;
		case '3': Out = 3; break;
		case '4': Out = 4; break;
		case '5': Out = 5; break;
		case '6': Out = 6; break;
		case '7': Out = 7; break;
		case '8': Out = 8; break;
		case '9': Out = 9; break;
		case '0': Out = 10;break;
		case '\"':Out = 11;break;
		case '\\':Out = 12;break;
		case '\'':Out = 13;break;
		case '*': Out = 14;break;
		case '=': Out = 15;break;
		case '/': Out = 16;break;
		case '+': Out = 17;break;
		case '-': Out = 18;break;
		case '_': Out = 19;break;
		case ';': Out = 20;break;
		case ':': Out = 21;break;
		case '\t':Out = 22;break;
		case '\n':Out = 23;break;
		case '\b':Out = 24;break;
		case ',': Out = 25;break;
		case '.': Out = 26;break;
		case 'a': Out = 27;break;
		case 'b': Out = 28;break;
		case 'c': Out = 29;break;
		case 'd': Out = 30;break;
		case 'e': Out = 31;break;
		case 'f': Out = 32;break;
		case 'g': Out = 33;break;
		case 'h': Out = 34;break;
		case 'i': Out = 35;break;
		case 'j': Out = 36;break;
		case 'k': Out = 37;break;
		case 'l': Out = 38;break;
		case 'm': Out = 39;break;
		case 'n': Out = 40;break;
		case 'o': Out = 41;break;
		case 'p': Out = 42;break;
		case 'q': Out = 43;break;
		case 'r': Out = 44;break;
		case 's': Out = 45;break;
		case 't': Out = 46;break;
		case 'u': Out = 47;break;
		case 'v': Out = 48;break;
		case 'w': Out = 49;break;
		case 'x': Out = 50;break;
		case 'y': Out = 51;break;
		case 'z': Out = 52;break;
		case 27 : Out = 53;break;
		default:  Out = 0; break;
	}
	return Out;
}

