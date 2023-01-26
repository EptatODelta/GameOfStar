#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "types.h"
#include "output.h"
#include <sys/types.h>
#include <sys/stat.h>

int M_SciNotatExp(double value) {
    if (value == 0) return 0;
    return (int) floor(log10(fabs(value)));
}


#define MAX_RETRIES 10
#define SLEEP_TIME 500000

void* allocate_memory(size_t size) {
    void* a = NULL;
    int retries = 0;

    while (retries < MAX_RETRIES) {
        a = (void*)malloc(size);
        if (a != NULL) {
            break;
        }
        retries++;
        usleep(SLEEP_TIME);
    }
    if (a == NULL) {
        printf("Error: Failed to allocate memory after %d retries.\n", MAX_RETRIES);
    }
    return a;
}



FILE* F_open(char *path, char *mode) {
    return fopen(path, mode);
}
void F_close(FILE* f) {
    if(f == NULL) { OutStr("Error 101: Couldn't access the file."); return;}
    else fclose(f);
}
Byte F_move(FILE* f, INT_32 position, Byte relation) {
    if(fseek(f, position, relation) != 0) return 1;
    else return 0;
}

int F_len(FILE* f) {
    if(f == NULL) { F_close(f); return 0; }
    int current_pos = ftell(f);
    if(F_move(f, 0, SEEK_SET) == 1) { return 0; }
    char a = 0; int b = 0;
    while(a != EOF) {
        a = getc(f); ++b;
    }
    if(F_move(f, current_pos, SEEK_SET) == 1) { return 0; }
    return b;
}
char* F_createBuffer(FILE*f) {
    if(f == NULL) { F_close(f); return 0; }
    if((f, 0, SEEK_SET) == 1) { return 0; }
    int length = F_len(f);
    char* buffer = (char*)allocate_memory(length);
    if(buffer == NULL) { OutStr("Error 102: Couldn't create the buffer."); return 0; }

    char a = 0; int b = 0;
    a = getc(f); 
    while(a != EOF) {
        buffer[b] = a;
        a = getc(f); 
        ++b;
    }
    buffer[length] = '\0';
    if(F_move(f, 0, SEEK_SET) == 1) { return 0; }

    return buffer;
}