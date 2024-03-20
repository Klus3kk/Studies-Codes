#include <stdio.h>
#include <math.h>
int main() {
    int n = 1,m = 1;
    double T = 0, T1 = 1, a = 1, b = 1, c = 1;
    for(int i = 1; i <= n; i++) {
        T1 = 1;
        for(int j = 1; j <= m; j++) {
            T1 *= (1+(a*pow(i,2) + b * pow(j,2) + c)/(pow(sin(i/j),2) + 2));
        }
        T += T1;
    }
    printf("%lf", T);
    return 0;
}