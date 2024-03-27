#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double A[10][10];
int m, n;

void read_matrix() {
    printf("Podaj liczbe wierszy: ");
    scanf("%d", &m);
    printf("Podaj liczbe kolumn: ");
    scanf("%d", &n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Tab[%d][%d] = ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
}

void sum_of_row() {
    int row;
    printf("Podaj numer wiersza: ");
    scanf("%d", &row);
    double sum = 0.0;
    for(int j = 0; j < n; j++) {
        sum += A[row][j];
    }
    printf("Suma elementow w wierszu %d: %lf\n", row, sum);
}

void sum_of_column() {
    int column;
    printf("Podaj numer kolumny: ");
    scanf("%d", &column);
    double sum = 0.0;
    for(int i = 0; i < m; i++) {
        sum += A[i][column];
    }
    printf("Suma elementow w kolumnie %d: %lf\n", column, sum);
}

int main() {
    char option;
    while(true) {
        printf("Podaj opcje: ");
        fflush(stdin);
        scanf("%c", &option);
        switch(option) {
            case '1':
                read_matrix();
                break;
            case '2':
                sum_of_row();
                break;
            case '3':
                sum_of_column();
                break;
            case '0':
                return 0;
            default:
                printf("Nieznana opcja\n");
        }
    }
    return 0;
}