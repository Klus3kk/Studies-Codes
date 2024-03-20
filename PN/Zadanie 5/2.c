#include <stdio.h>
#include <math.h>

int main() {
    int m = 1;
    double I = 1.0;
    for(int j = 1; j <= m; j++) {
        I *= sqrt((pow(j,2) + (2.0 * j) - 1.0) / ((3.0*j) - 1.0));
    }

    printf("%lf", I);
    return 0;
}