#include <stdio.h>

int main() {
    int N = 5;
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
        if(A[i] > B[i]) {
            C[i] = 2 * A[i] + B[i];
        } else {
            C[i] = A[i] - 2*B[i];
        }
        printf("A[i]: %lf, B[i]: %lf: %lf\n", A[i], B[i], C[i]);
    }
    return 0;
}