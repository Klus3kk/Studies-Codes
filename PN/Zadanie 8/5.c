#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

int main() {
    int N, M;
    double X;
    printf("Podaj wielkosci macierzy (N, M): ");
    scanf("%d %d", &N, &M);
    printf("Podaj wartosc X: ");
    scanf("%lf", &X);
    double **A = malloc(N * sizeof(double*)); // dynamic array 1D
    for(int i = 0; i < N; i++) {
        A[i] = malloc(M * sizeof(double)); // dymamic array 2D
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("Podaj element [%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
    int count = 0;
    for(int j = 0; j < M; j++) {
        double sum = 0.0;
        for(int i = 0; i < N; i++) {
            sum += A[i][j];
        }
        if(sum > X) {
            count++;
        }
    }
    printf("Liczba kolumn z suma wieksza od X: %d\n", count);
    for(int i = 0; i < N; i++) {
        free(A[i]); // free memory allocated for 2D array (malloc)
    }
    free(A);
    return 0;   
}