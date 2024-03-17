#include <stdio.h>
#include <math.h>
int main(void) {
    float a = 3e-1, b = 4e-1;
    printf("%g\n", 1e1 * sqrt(a * a + b * b));
    return 0;
}