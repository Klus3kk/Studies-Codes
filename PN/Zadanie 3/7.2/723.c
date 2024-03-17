#include <stdio.h>
#include <math.h>

int main() {
    double l = 0.1;
    for (double i = 1; i <= 10; i++) {
        printf("%lf\n", log10(l*i));
    }
    return 0;
}