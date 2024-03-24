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

void przekatna(int n, int A[n][n]) {
    int suma = 0;
    for(int i = 0; i < n; i++) {
        suma += A[i][i];
    }
    printf("\n%d", suma);
}

int main() {
    int n;
    printf("Podaj wielkosc matrycy (n): ");
    scanf("%d", &n);
    int A[n][n];
    napisz_dane(n, A);
    przekatna(n, A);
    return 0;
}