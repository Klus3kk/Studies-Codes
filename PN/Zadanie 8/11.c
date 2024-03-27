#include <stdio.h>

int main() {
    int N, M;
    printf("Podaj liczbe wierszy N: ");
    scanf("%d", &N);
    printf("Podaj liczbe kolumn M: ");
    scanf("%d", &M);

    double K[10][10];

    printf("Podaj elementy tablicy K: ");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%lf", &K[i][j]);
        }
    }

    int top = 0, bottom = N - 1, left = 0, right = M - 1;
    while(top <= bottom && left <= right) {
        for(int j = left; j <= right; j++) {
            printf("%lf ", K[top][j]);
        }
        top++;
        for(int i = top; i <= bottom; i++) {
            printf("%lf ", K[i][right]);
        }
        right--;
        if(top <= bottom) {
            for(int j = right; j >= left; j--) {
                printf("%lf ", K[bottom][j]);
            }
            bottom--;
        }
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                printf("%lf ", K[i][left]);
            }
            left++;
        }
    }
    printf("\n");

    return 0;
}