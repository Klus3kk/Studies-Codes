#include <stdio.h>
#include <math.h>
#define A 3e-200
#define B 4e-200
#define C 1e200
int main(void) {
    double m;
    m = C * sqrt(A * A + B * B);
    printf("m= %g\n", m);
    return(0);
}