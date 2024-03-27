#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

int main() {
    double x;
    while(1) {
        char choice;
        fflush(stdin);
        printf("N - nowa liczba x\nS - sinus liczby x\nP - pierwiastek kwadratowy z x\nQ - wyjscie\n");
        scanf("%c", &choice);
        switch(choice) {
            case 'N':
                printf("Podaj nowa liczbe x: \n");
                scanf("%lf", &x);
                break;
            case 'S':
                printf("%lf\n", sin(x));
                break;
            case 'P':
                if(x >= 0) {
                    printf("%lf\n", sqrt(x));
                } else {
                    printf("Nie jest mozliwe obliczenie pierwiastka\n");
                }
                break;
            case 'Q':
                printf("Koniec\n");
                return 0;
            default:
                printf("Nieprawidlowy wybor\n");
                return 0;
        }
    }
    return 0;   
}