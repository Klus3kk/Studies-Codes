#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// idk if it's correct 0_0 
#define MAX_KANDYDATOW 20
#define MAX_HASLA 200

typedef struct {
    int numer;
    char imie[50];
    char nazwisko[50];
} Kandydat;

typedef struct {
    int numer;
    char haslo[9];
} Glos;

int main() {
    Kandydat kandydaci[MAX_KANDYDATOW];
    char hasla[MAX_HASLA][9];
    Glos glosy[MAX_HASLA];
    int glosyKandydatow[MAX_KANDYDATOW] = {0};
    int liczbaKandydatow = 0;
    int liczbaHasel = 0;
    int liczbaGlosow = 0;
    int liczbaGlosowWaznych = 0;
    int liczbaGlosowNiewaznych = 0;
    int liczbaGlosowWielokrotnych = 0;

    FILE *plikK = fopen("K.txt", "r");
    FILE *plikH = fopen("H.txt", "r");
    FILE *plikG = fopen("G.txt", "r");

    if (plikK == NULL || plikH == NULL || plikG == NULL) {
        printf("Nie moge otworzyc pliku\n");
        return 1;
    }

    while (fscanf(plikK, "%d", &liczbaKandydatow) == 1) {
        liczbaKandydatow++;
    }

    while (fscanf(plikH, "%s", hasla[liczbaHasel]) == 1) {
        liczbaHasel++;
    }

    while (fscanf(plikG, "%d", &glosy[liczbaGlosow].numer) == 2) {
        liczbaGlosow++;
    }

    for (int i = 0; i < liczbaGlosow; i++) {
        int jestHaslo = 0;
        for (int j = 0; j < liczbaHasel; j++) {
            if (strcmp(glosy[i].haslo, hasla[j]) == 0) {
                jestHaslo = 1;
                break;
            }
        }
        if (!jestHaslo) {
            liczbaGlosowNiewaznych++;
            continue;
        }

        int jestKandydat = 0;
        for (int j = 0; j < liczbaKandydatow; j++) {
            if (glosy[i].numer == j+1) {
                jestKandydat = 1;
                glosyKandydatow[j]++;
                break;
            }
        }
        if (!jestKandydat) {
            liczbaGlosowNiewaznych++;
            continue;
        }

        int jestWielokrotny = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(glosy[i].haslo, glosy[j].haslo) == 0) {
                jestWielokrotny = 1;
                break;
            }
        }
        if (jestWielokrotny) {
            liczbaGlosowWielokrotnych++;
            continue;
        }

        liczbaGlosowWaznych++;
    }

    printf("Liczba wszystkich oddanych glosow: %d\n", liczbaGlosow);
    printf("Liczba glosow waznych: %d\n", liczbaGlosowWaznych);
    printf("Liczba glosow niewaznych: %d\n", liczbaGlosowNiewaznych);
    printf("Liczba glosow wielokrotnych: %d\n", liczbaGlosowWielokrotnych);

    fclose(plikK);
    fclose(plikH);
    fclose(plikG);

    return 0;
}