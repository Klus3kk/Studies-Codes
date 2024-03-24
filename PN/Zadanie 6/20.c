#include <stdio.h>

void napisz_dane(int n, int A[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    table_print(n, A);
}


void table_print(int n, int A[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void mnozenie_macierzy(int n, int A[n][n], int B[n][n]) {
    int C[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = 0;
            for(int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    table_print(n, C);
}

int main() {
    int n;
    printf("Podaj wielkosc matrycy (n): ");
    scanf("%d", &n);
    int A[n][n];
    int B[n][n];
    napisz_dane(n, A);
    napisz_dane(n, B);
    mnozenie_macierzy(n, A, B);
    return 0;
}