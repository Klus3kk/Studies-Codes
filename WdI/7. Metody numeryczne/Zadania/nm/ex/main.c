#include <stdio.h>

float compute_ex(int n, float x) {
    double total = 0, t;
    double num = 1.0, den =1.0;
    int i;
    for (i = 1; i <= n; i++){
        t = num / den;
        total += t;
        num *= x;
        den *= i;
    }
    return total;
}

int main () {
    int n;
    float x;
    scanf("%d %f", &n, &x);
    printf("%g\n", compute_ex(n, x));
    return 0;
}

