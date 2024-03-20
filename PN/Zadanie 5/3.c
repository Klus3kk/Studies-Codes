#include <stdio.h>
#include <math.h>
int main() {
    int n = 1,m = 1;
    double R = 0, R1 = 1;
    for(int i = 1; i <= n; i++) {
        R1 = 1;
        for(int j = 1; j <= m; j++) {
            R1 *= (pow(i,2) + pow(j,2) - 1.0) / ((2 * i) + (3 * j) + 4.0);
        }
        R += R1;
    }
    printf("%lf", R);
    return 0;
}