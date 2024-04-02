#include <stdio.h>
#include <math.h>

#define MAX_N 100

typedef struct {
    int numer_serii;
    double pomiar[5];
} Pomiar;

typedef struct {
    int numer_serii;
    double A;
    double B;
} Wynik;

Pomiar pomiary[MAX_N];
Wynik wyniki[MAX_N];
int N;

double P1(double x, double y, double z) {
    return (x + 2 * y - z + 1) / (2*pow(x,2) + pow(y,2) + pow(z,2) + 1);
}

double P2(double a, double b, double c) {
    return 1 + ((a + c)/(pow(b,2) + 1));
}

void wczytaj() {
    char nazwa_pliku[100];
    printf("Podaj nazwę pliku: ");
    scanf("%s", nazwa_pliku);

    FILE *file = fopen(nazwa_pliku, "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku.\n");
        return;
    }

    fscanf(file, "%d", &N);
    for (int i = 0; i < N; i++) {
        fscanf(file, "%d", &pomiary[i].numer_serii);
        for (int j = 0; j < 5; j++) {
            fscanf(file, "%lf", &pomiary[i].pomiar[j]);
        }
    }

    fclose(file);
}

void przetwarzajF() {
    for (int i = 0; i < N; i++) {
        wyniki[i].numer_serii = pomiary[i].numer_serii;
        wyniki[i].A = P1(pomiary[i].pomiar[0], pomiary[i].pomiar[1], pomiary[i].pomiar[2]);
        wyniki[i].B = P2(pomiary[i].pomiar[2], pomiary[i].pomiar[3], pomiary[i].pomiar[4]);
    }
}

void przetwarzajG() {
    for (int i = 0; i < N; i++) {
        wyniki[i].numer_serii = pomiary[i].numer_serii;
        wyniki[i].A = P2(pomiary[i].pomiar[1], pomiary[i].pomiar[3], pomiary[i].pomiar[4]);
        wyniki[i].B = P1(pomiary[i].pomiar[0], pomiary[i].pomiar[1], pomiary[i].pomiar[3]);
    }
}

void zapisz() {
    char nazwa_pliku[100];
    printf("Podaj nazwę pliku: ");
    scanf("%s", nazwa_pliku);

    FILE *file = fopen(nazwa_pliku, "w");
    if (file == NULL) {
        printf("Nie można otworzyć pliku.\n");
        return;
    }

    fprintf(file, "%d\n", N);
    for (int i = 0; i < N; i++) {
        fprintf(file, "%d %lf %lf\n", wyniki[i].numer_serii, wyniki[i].A, wyniki[i].B);
    }
    for (int i = 0; i < N; i++) {
        fprintf(file, "%d ", pomiary[i].numer_serii);
        for (int j = 0; j < 5; j++) {
            fprintf(file, "%lf ", pomiary[i].pomiar[j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    char opcja;
    int wczytano = 0;

    while (1) {
        printf("Podaj opcje: L - wczytaj dane, F - przetwarzaj dane zgodnie z funkcja F, G - przetwarzaj dane zgodnie z funkcja G, Z - zapisz dane, Q - zakoncz program\n");
        scanf(" %c", &opcja);

        if (opcja == 'L') {
            wczytaj();
            wczytano = 1;
        } else if (opcja == 'F' && wczytano) {
            przetwarzajF();
        } else if (opcja == 'G' && wczytano) {
            przetwarzajG();
        } else if (opcja == 'Z' && wczytano) {
            zapisz();
        } else if (opcja == 'Q') {
            break;
        } else {
            printf("Nieprawidlowa opcja lub opcja wybrana przed wczytaniem danych.\n");
        }
    }

    return 0;
}