#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double A[10][5];
int ile_w;

void read_array() {
    printf("Podaj liczbe wierszy: ");
    scanf("%d", &ile_w);
    for(int i = 0; i < ile_w; i++) {
        for(int j = 0; j < 5; j++) {
            printf("Tab[%d][%d] = ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
}

void sum_greater_than_X() {
    double X;
    printf("Podaj wartosc X: ");
    scanf("%lf", &X);
    for(int i = 0; i < ile_w; i++) {
        double sum = 0.0;
        for(int j = 0; j < 5; j++) {
            if(A[i][j] > X) {
                sum += A[i][j];
            }
        }
        printf("Suma elementow wiekszych od X w wierszu %d: %lf\n", i, sum);
    }
}

void product_of_N_elements() {
    int N;
    printf("Podaj wartosc N: ");
    scanf("%d", &N);
    for(int j = 0; j < 5; j++) {
        double product = 1.0;
        for(int i = 0; i < N; i++) {
            product *= A[i][j];
        }
        printf("Iloczyn %d poczatkowych elementow w kolumnie %d: %lf\n", N, j, product);
    }
}

void count_rows_with_first_greater_than_last() {
    int count = 0;
    for(int i = 0; i < ile_w; i++) {
        if(A[i][0] > A[i][4]) {
            count++;
        }
    }
    printf("Liczba wierszy, w ktorych poczatkowy element jest wiekszy od ostatniego: %d\n", count);
}

void count_columns_with_zero() {
    int count = 0;
    for(int j = 0; j < 5; j++) {
        for(int i = 0; i < ile_w; i++) {
            if(A[i][j] == 0.0) {
                count++;
                break;
            }
        }
    }
    printf("Liczba kolumn, w ktorych wystepuje przynajmniej jedna wartosc 0: %d\n", count);
}

int main() {
    char option;
    while(true) {
        printf("Podaj opcje: ");
        fflush(stdin);
        scanf("%c", &option);
        switch(option) {
            case '1':
                read_array();
                break;
            case '2':
                sum_greater_than_X();
                break;
            case '3':
                product_of_N_elements();
                break;
            case '4':
                count_rows_with_first_greater_than_last();
                break;
            case '5':
                count_columns_with_zero();
                break;
            case '0':
                return 0;
            default:
                printf("Nieznana opcja\n");
        }
    }
}