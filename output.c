#include <unistd.h>
#include <stdio.h>

#include "strutil.h"
#include "types.h"

void OutChar(const char ch) {
    write(1,&ch,1);
    return;
}
void OutNum(int num) {
    char output[10];
    strFill(output, 11);

    for(int i = 0; i < 10 && num > 0; i++) {
        output[i] = 48 + (num % 10);
        num /= 10;
    }

    for(int i = 9; i >= 0; i--) {
        if(output[i] == 11) continue;
        else OutChar(output[i]);
    }
}

//String Outputs
void OutStr(const char* String) {
    short length = strLen(String);
    write(1, String, length);
}
void OutStrLim(const char* String, const short maxLimit) {
    short length = strLen(String);
    if( length < maxLimit ) write(1, String, length);
    else write(1, String, maxLimit);
}
void OutStrLines(const char* String, const short limit, const short linesLimit) {
    const short length = strLen(String); short tlength = length;
    char tempStr[length];
    strInit(tempStr, length);
    if ((strCopy(String, tempStr)) == 5) {
        printf("%d, %d, %d\n%s\n%s\n", length, strLen(tempStr), strLen(String), tempStr, String); 
        printf("AAAA"); 
        fflush(stdout);
        return;
    }
    short lines = 1;


    while(length > 0 && lines <= linesLimit) {
        if ( tlength <= limit ) {
            write(1, tempStr, tlength);
            break;
        }
        write(1, tempStr, limit);
        strShift(tempStr, -limit);
        tlength -= limit;
        lines++;
        OutChar('\n');
    }
}