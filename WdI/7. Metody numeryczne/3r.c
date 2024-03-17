#include <stdio.h>
#include <math.h>
#define A 3e-200
#define B 4e-200
#define C 1e200
int main(void) {
    double m;
    m = C * A * sqrt(1 + (B / A) * (B / A));
    printf("m = %g\n", m);
    return(0);
}
 