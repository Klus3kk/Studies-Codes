#include<stdio.h>
double p(double x, int n, double a[]) {
if (n == 0) return a[0];
    else return p(x, n - 1, a)* x + a[n];
}
void main(void) {
    double a[] = { 1e300, 0, 0, 0, 0, 0, 0, 0, 0 };
    printf("%g\n", p(1e-50, 8, a));
    return;
}