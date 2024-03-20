#include <stdio.h>
#include <math.h>
int main() {
    int a = 4,b = 1;
    double T = 1, T1 = 0, p = 1, q = 1;
    for(int k = 1; k <= a; k++) {
        for(int h = 1; h <= b; h++) {
            T1 += sqrt((pow(sin(p * k + q * h),2) + 1.14) / log(3*cos(q*k - p*h)));
        }
        T *= T1;
    }
    if(isnan(T)) {
        printf("%d", 1);
    } else {
        printf("%lf", T);
    }

    return 0;
}