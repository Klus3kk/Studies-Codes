#include <stdio.h>
#include <math.h>
int main() {
    int n = 10;
    double S = 0,a = 5;
    for(int i = 1; i <= n; i++) {
        S += (a*(pow(i,3)) - 7) / (pow(i,2) + 1);
    }
    printf("%lf", S);
    return 0;
}