#include <stdio.h>

void napisz_dane(int n, int A[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}

void calculate_ratio(int n, int A[n][n]) {
    int sum_above = 0;
    int sum_below = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i < j) {
                sum_above += A[i][j];
            } else if(i > j) {
                sum_below += A[i][j];
            }
        }
    }

    if(sum_below != 0) {
        float ratio = (float)sum_above / sum_below;
        printf("\nRatio: %.2f", ratio);
    } else {
        printf("\nCannot calculate ratio. Sum below diagonal is 0.");
    }
}

int main() {
    int n;
    printf("Podaj wielkosc matrycy (n): ");
    scanf("%d", &n);
    int A[n][n];
    napisz_dane(n, A);
    calculate_ratio(n, A);
    return 0;
}