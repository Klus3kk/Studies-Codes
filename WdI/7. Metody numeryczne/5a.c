#include<stdio.h>
double Power(double b, int k) {
    double res = 1.0;
    int i;
    for (i = 1; i <= k; i++)
        res *= b;
    return res;
}
double p(double x, int n, double a[]) {
    double result = 0.0;
    int k;
    for (k = 0; k <= n; k++)
        result += a[k] * Power(x, k);
    return result;
}
void main(void) {
    double a[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1e300 };
    printf("%g\n", p(1e-50, 8, a));
    return;
}