#include <stdio.h>

int main() {
    int N = 5;
    double A[N], B[N];
    printf("Wprowadz elementy A: \n");
    for(int i = 0; i < N; i++) {
        scanf("%lf", &A[i]);
    }
    printf("Wprowadz elementy B: \n");
    for(int i = 0; i < N; i++) {
        scanf("%lf", &B[i]);
    }
    for(int i = 0; i < N;i++) {
        printf("%lf\n", A[i]);
        printf("%lf\n", B[i]);
    }
    return 0;
}