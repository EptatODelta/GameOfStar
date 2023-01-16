#include "types.h"

I_Func M_iExp(INT_64 Base, UINT_64 Exponent) {
    if(Exponent == 0) { return 1L; }
    INT_64 out = 1;
    while(1) {
        if((Exponent % 2) == 1) {
            out *= Base;
        }
        Exponent /= 2;
        if(Exponent == 0) break;
        Base *= Base;
    }
    return out;
}
M_Func M_fExp(FINT_64 Base, INT_64 Exponent) {
    if(Exponent == 0) { return 1L; }
    if(Exponent < 0) { return 1/M_fExp(Base, -Exponent); }
    FINT_64 out = 1;
    while(1) {
        if((Exponent % 2) == 1) {
            out *= Base;
        }
        Exponent /= 2;
        if(Exponent == 0) break;
        Base *= Base;
    }
    return out;
}

