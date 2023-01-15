#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "strutil.h"
#include "types.h"
#include "conctrl.h"
#include "datautil.h"


//Cautious! Cursor position might become off-sync when trying to print out tabulation, so use it only when required!
void OutChar(const char ch) {
    write(1,&ch,1);
    fflush(stdout);

    switch(ch) {
        case '\n': CursorPos.Y++; break;
        case '\b': CursorPos.X--; break;
        case '\0': break;
        case 7: break;
        default:   CursorPos.X++; break;
    }
    return;
} void OutChars(const char ch, const short number) {
    if(number <= 0) return;
    switch(ch) {
        case '\n': CursorPos.Y+=number; break;
        case '\b': CursorPos.X-=number; break;
        case '\0': break;
        case 7: break;
        default:   CursorPos.X+=number; break;
    }
    char buf[number];
    strInit(buf, number);
    strFill(buf, ch);
    write(1,buf,number);
    fflush(stdout);
    return;
}

void OutStr(const char*);

void OutNum(const long long signed int num, const Byte type, const Byte base, const double value) {
    if(type & OUTNUM__IS_FLOAT) goto floating;

    long long signed int temp = num;
    if(temp == 0) {
        write(STDOUT_FILENO, "0", 1);
        CursorPos.X++;
        return;
    }
    if(base <= 1) {
        OutStr("0");
        return;
    }
    if(temp < 0) {
        if (!(type & OUTNUM__UNSIGNED)) { write(STDOUT_FILENO, "-", 1); fflush(stdout); CursorPos.X++; }
        temp = -temp;
    }

    if(type & OUTNUM__BASE_OUTPUT) {
        if(!(type & OUTNUM__BASE_OUTPUT_TYPE)) {
            switch(base) {
                case 0: OutStr("0O"); break;
                case 1: OutStr("0N"); break;
                case 2: OutStr("0b"); break;
                case 3: OutStr("0t"); break;
                case 4: OutStr("0qt");break;
                case 5: OutStr("0qn");break;
                case 6:OutStr("0sex");break;
                case 7: OutStr("0sp");break;
                case 8: OutStr("0o"); break;
                case 9: OutStr("0nn");break;
                case 10:OutStr("0d"); break;
                case 11:OutStr("0el");break;
                case 12:OutStr("0z");break;
                case 13:OutStr("0bd");break;
                case 14:OutStr("0bsp");break;
                case 15:OutStr("0trq");break;
                case 16: OutStr("0x");break;
                case 17: OutStr("0sub");break;
                case 18: OutStr("0ts");break;
                case 19: OutStr("0uts"); break;
                case 20: OutStr("0vg");break;
                case 21:OutStr("0tsp"); break;
                case 22: OutStr("0be"); break;
                case 23: OutStr("0ube"); break;
                case 24: OutStr("0tsx"); break;
                case 25: OutStr("0pqn"); break;
                case 26: OutStr("0bkd");break;
                case 27: OutStr("0trin");break;
                case 28: OutStr("0ttsp");break;
                case 29: OutStr("0uttsp");break;
                case 30: OutStr("0psx"); break;
                case 31: OutStr("0upsx");break;
                case 32:OutStr("0ttoc"); break;
                case 33: OutStr("0te"); break;
                case 34: OutStr("0bsub"); break;
                case 35: OutStr("0psp"); break;
                case 36: OutStr("0nfm"); break;
                case 37: OutStr("0unfm");break;
                case 38: OutStr("0btsx");break;
                case 39: OutStr("0td");break;
                case 40: OutStr("0po");break;
                case 41: OutStr("0upo"); break;
                case 42: OutStr("0hsp");break;
                case 43:OutStr("0uhsp"); break;
                case 44: OutStr("0tte"); break;
                case 45: OutStr("0pnn"); break;
                case 46: OutStr("0bnbe"); break;
                case 47: OutStr("0ubnbe"); break;
                case 48: OutStr("0ho");break;
                case 49: OutStr("0hs");break;
                case 50: OutStr("0pg");break;
                case 51: OutStr("0trsub");break;
                case 52: OutStr("0trd"); break;
                case 53: OutStr("0utrd");break;
                case 54:OutStr("0hnn"); break;
                case 55: OutStr("0pe"); break;
                case 56: OutStr("0hpo"); break;
                case 57: OutStr("0tntsx"); break;
                case 58: OutStr("0btsp"); break;
                case 59: OutStr("0ubtsp");break;
                case 60: OutStr("0hg");break;
                case 61: OutStr("0uhg");break;
                case 62: OutStr("0bps");break;
                case 63: OutStr("0hpnn"); break;
                case 64: OutStr("0thg");break;
                case 65:OutStr("0pnd"); break;
                case 66: OutStr("0hxel");break;
                default: OutStr("0+"); break;
            }
        }
        else {
            OutNum(base, Null, 10, 0);
            OutChar('_');
        }
    }

    char buffer[128];
    int i = 0;
    while (temp > 0) {
        buffer[i++] = (temp % base) + '0' + (((type & OUTNUM__POST_BASE11) == 2) && ((temp % base) >= 10) ? 7 : 0) + (((type & OUTNUM__POST_BASE11) == 2) && ((temp % base) >= 36) ? 6 : 0);
        temp /= base;
    }
    CursorPos.X += i;
    while (i-- > 0) {
        write(STDOUT_FILENO, &buffer[i], 1);
        if (i % 3 == 0 && i != 0 && type & OUTNUM__FORMATTING) { OutChar( ((type & OUTNUM__BASE_OUTPUT >= 1 && type & OUTNUM__BASE_OUTPUT_TYPE == 0) ? '_' : ' ') ); }
    }
    return;

    floating:
    Byte negative = (value < 0);
    double tempInt = value;
    if (negative) { tempInt = -value; }
    if( tempInt >= QWORD_SLIMIT ) { OutStr("FVcbO:801"); return; }
    long long intPart = (long long) tempInt;
    double fracPart = tempInt - intPart;
    if (!(type & OUTNUM__UNSIGNED) && negative ) { write(STDOUT_FILENO, "-", 1); fflush(stdout); CursorPos.X++; }
    fflush(stdout);
    OutNum(intPart, OUTNUM__UNSIGNED, 10, 0);
    OutChar((((type & OUTNUM__FLOAT_PERIOD) >= 1) ? ',' : '.'));

    for(int i = 0; i<base; i++) {
        fracPart *= 10;
        unsigned int digit = (int) fracPart;
        OutChar(digit + '0');
        if (fracPart - (double)digit > 1e-6) fracPart -= digit;
        else break;
    }
    return;
}



//String Outputs
void OutStr(const char* String) {
    short length = strLen(String);
    for(int i = 0; i < length; i++) {
        switch(String[i]) {
            case '\n': CursorPos.Y++; break;
            case '\b': CursorPos.X--; break;
            case '\0': break;
            case 7: break;
            default:   CursorPos.X++; break;
        }
    }
    write(1, String, length);
}
void OutStrLim(const char* String, const short maxLimit) {
    short length = strLen(String);
    if( length < maxLimit ) { write(1, String, length); CursorPos.X+=length; }
    else { write(1, String, maxLimit); CursorPos.X+=maxLimit; }
}





void OutText(const char* String, const short LineLength, const short LineNum, const Byte type) {
    short length = strLen(String), maxWordLen = strMaxWordLen(String), Lines = 0, Chars = 0;

    char* TempStr = (char*) malloc (maxWordLen+1);
    if(TempStr == NULL) { return; }

    strInit(TempStr, maxWordLen);

    for(int i = 0; i < length;) {
        strInit(TempStr, maxWordLen);
        for(int j = 0; ; j++) //fill TempStr word buffer
        {
            if (String[j+i] == ' ' || j==maxWordLen) { 
                TempStr[j] = ' '; 
                i+=j; break; 
            }
            TempStr[j] = String[i+j];
        }

        if(Lines >= LineNum) break;
        

        if((Chars % LineLength) + strFindChFirst(TempStr, ' ') + 1 >= LineLength) {
            OutChar('\n');
            Lines++;
        }
        
        OutStrLim(TempStr, strFindChFirst(TempStr, ' '));
        
        Chars=i; Chars+=1;
        i++;
        OutChar(' ');
    }

    free(TempStr);
    return;
}