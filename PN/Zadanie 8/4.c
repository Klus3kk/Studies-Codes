#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

void dodawanie(double A[][50], int N, int M) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("Podaj element [%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
}

int main() {
    int N,M;
    double max;
    printf("Podaj wielkosci macierzy (N, M): ");
    scanf("%d %d", &N, &M);    
    while(N > 50 || M > 50) {
        printf("Podaj mniejsze wartosci N i M: ");
        scanf("%d %d", &N, &M);
    }
    double A[50][50];
    dodawanie(A, N, M);
    for(int i = 0; i < N; i++) {
        max = 0.0;
        for(int j = 0; j < M; j++) {
            if(A[i][j] > max) {
                max = A[i][j];
            }
        }
        printf("Wiersz %d: %lf\n", i + 1,max);
    }
    return 0;   
}