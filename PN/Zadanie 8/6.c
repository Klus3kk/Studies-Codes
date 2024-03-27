#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    double A[20][20];
    int m = 0, n = 0;
    bool initialized = false;
    char command;
    while(true) {
        printf("Podaj polecenie: ");
        scanf(" %c", &command);
        switch(command) {
            case 'N':
            case 'n':
                printf("Podaj wielkosci macierzy (m, n): ");
                scanf("%d %d", &m, &n);
                for(int i = 0; i < m; i++) {
                    for(int j = 0; j < n; j++) {
                        printf("Podaj element [%d][%d]: ", i, j);
                        scanf("%lf", &A[i][j]);
                    }
                }
                initialized = true;
                break;
            case 'W':
            case 'w':
                if(!initialized) {
                    printf("Macierz nie zostala zainicjalizowana.\n");
                    break;
                }
                for(int i = 0; i < m; i++) {
                    double sum = 0.0;
                    for(int j = 0; j < n; j++) {
                        sum += A[i][j];
                    }
                    printf("Suma wiersza %d: %lf\n", i, sum);
                }
                break;
            case 'K':
            case 'k':
                if(!initialized) {
                    printf("Macierz nie zostala zainicjalizowana.\n");
                    break;
                }
                for(int j = 0; j < n; j++) {
                    double sum = 0.0;
                    for(int i = 0; i < m; i++) {
                        sum += A[i][j];
                    }
                    printf("Suma kolumny %d: %lf\n", j, sum);
                }
                break;
            case 'Q':
            case 'q':
                return 0;
            default:
                printf("Nieprawidlowe polecenie.\n");
        }
    }
}