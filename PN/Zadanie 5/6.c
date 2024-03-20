#include <stdio.h>
#include <math.h>

int main() {
    double x1 = 1.0,x2 = 5.0,K,kr = 1.0;
    for(double x = x1; x <= x2; x += kr) {
        K = ((sin(x) - 1) / (pow(sin(pow(x,2)),2) + 1));
        printf("%lf : %lf\n", x,K);
    }
    return 0;
}