#ifndef PROGSE_H_
#define PROGSE_H_

void resetMem(float*);
void atStart(pthread_t, pthread_t, pthread_attr_t, pthread_attr_t, void* (*InputThreadProcedure)(void*), void* (*TimeThreadProcedure)(void*));
void atEnd(int);

#endif