#include <stdio.h>
#define N 7
double e(double x) {
    double Sum = 0, T;
    double num = 1.0;
    double den = 1.0;
    int i;
    for (i = 1; i <= N; i++) {
        T = num / den;
        Sum += T;
        num *= x;
        den *= i;
    }
    return Sum;
}
int main(void) {
    printf("%g \n", e(1));
    return(0);
}