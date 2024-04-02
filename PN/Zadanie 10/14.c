#include <stdio.h>
#include <math.h>

double obliczB(double x) {
    return pow(sin(x),5) + pow(cos(x),3) + 1;
}

double obliczC(double x) {
    return log(x + 2.35) - 4.22;
}

int main() {
    char plikWejsciowy[50];
    char plikWyjsciowy[50];
    double liczba;

    printf("Podaj nazwe pliku wejsciowego: ");
    scanf("%s", plikWejsciowy);

    printf("Podaj nazwe pliku wyjsciowego: ");
    scanf("%s", plikWyjsciowy);

    FILE *wejscie = fopen(plikWejsciowy, "r");
    FILE *wyjscie = fopen(plikWyjsciowy, "w");

    if (wejscie == NULL || wyjscie == NULL) {
        printf("Nie moge otworzyc pliku\n");
        return 1;
    }

    while (fscanf(wejscie, "%lf", &liczba) == 1) {
        double wynik;
        if (liczba < 0) {
            wynik = -1.07;
        } else if (liczba <= 103.34) {
            wynik = obliczB(liczba);
        } else {
            wynik = obliczC(liczba);
        }
        fprintf(wyjscie, "%lf\n", wynik);
    }

    fclose(wejscie);
    fclose(wyjscie);

    return 0;
}