#include <stdio.h>
#include <math.h>

int f(int a, int b) {
    if(a>b) {
        return pow(a,2) + 1;
    } else {
        return b + 2;
    }
}

double g(int k) {
    return sin(k+1.5)-cos(k-1.5);
}

int main() {
    int n,m;
    printf("Podaj n i m: ");
    scanf("%d %d", &n, &m);
    double R = 0, R1 = 1;
    for(int i = 1; i <= n; i++) {
        R1 = 1;
        for(int j = 1; j <= m; j++) {
            R1 *= ((2*f(i,j)) * g(i) + 1)/(f(i,j) + 3 * g(j));
        }
        R += R1;
    }
    printf("%lf", R);
    return 0;
}