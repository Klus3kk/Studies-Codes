#include <stdio.h>
#include <math.h>
int main() {
    int N = 6;
    double A[N], B[N], C[N];
    printf("Wprowadz elementy A: \n");
    for(int i = 0; i < N; i++) {
        scanf("%lf", &A[i]);
    }
    printf("Wprowadz elementy B: \n");
    for(int i = 0; i < N; i++) {
        scanf("%lf", &B[i]);
    }
    for(int i = 0; i < N;i++) {
        double L = pow(A[i],2) + B[i] * i;
        double M = 2 * A[i] * i - 5;
        if(M == 0.0) {
            printf("%d\n", 1);
        } else {
            C[i] = L/M;
            printf("A[i]: %lf, B[i]: %lf: %lf\n", A[i], B[i], C[i]);
        }
    }
    return 0;
}