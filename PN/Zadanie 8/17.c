#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

double calculateS(double x) {
    return 3 * sin(x + 0.15);
}

double calculateP(double x) {
    return pow(x, 2) + 3;
}

double calculateF(double x) {
    return pow(x, 4) + 2 * pow(x, 3) - 4 * pow(x, 2) + 8 * x - 16;
}

int main() {
    double x;
    char choice;
    bool isXEntered = false;

    while(1) {
        printf("\nN. Wczytaj nowa wartosc zmiennej x\nS. Oblicz: 3sin(x+0.15)\nP. Oblicz: x^2 + 3\nF. Oblicz: x^4 + 2x^3 - 4x^2 + 8x - 16\nQ. Koniec programu\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'N':
            case 'n':
                printf("Podaj wartosc x: ");
                scanf("%lf", &x);
                isXEntered = true;
                break;
            case 'S':
            case 's':
                if(isXEntered) {
                    printf("Wynik: %lf\n", calculateS(x));
                } else {
                    printf("Najpierw wprowadz wartosc x.\n");
                }
                break;
            case 'P':
            case 'p':
                if(isXEntered) {
                    printf("Wynik: %lf\n", calculateP(x));
                } else {
                    printf("Najpierw wprowadz wartosc x.\n");
                }
                break;
            case 'F':
            case 'f':
                if(isXEntered) {
                    printf("Wynik: %lf\n", calculateF(x));
                } else {
                    printf("Najpierw wprowadz wartosc x.\n");
                }
                break;
            case 'Q':
            case 'q':
                return 0;
        }
    }

    return 0;
}