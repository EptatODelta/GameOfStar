#ifndef DATAUTIL_H_
#define DATAUTIL_H_

int M_SciNotatExp(double);
void* allocate_memory(size_t);
FILE* F_open(char*, char*);
void F_close(FILE*);
Byte F_move(FILE*, INT_32, Byte);
int F_len(FILE*);
char* F_createBuffer(FILE*);

#endif