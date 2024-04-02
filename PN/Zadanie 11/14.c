#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// wow
typedef struct {
    char imie[50];
    int numerStartowy;
    int skok1;
    int skok2;
    int sumaSkokow;
} Zawodnik;

int porownaj1(const void* a, const void* b) {
    Zawodnik* z1 = *(Zawodnik**)a;
    Zawodnik* z2 = *(Zawodnik**)b;
    if (z1->skok1 != z2->skok1) {
        return z1->skok1 - z2->skok1;
    } else {
        return z1->numerStartowy - z2->numerStartowy;
    }
}

int porownaj2(const void* a, const void* b) {
    Zawodnik* z1 = *(Zawodnik**)a;
    Zawodnik* z2 = *(Zawodnik**)b;
    if (z1->sumaSkokow != z2->sumaSkokow) {
        return z2->sumaSkokow - z1->sumaSkokow;
    } else {
        return z1->numerStartowy - z2->numerStartowy;
    }
}

int main() {
    FILE* plik = fopen("ListaStartowa.txt", "r");
    if (plik == NULL) {
        printf("Nie można otworzyc pliku.\n");
        return 1;
    }

    Zawodnik** zawodnicy = NULL;
    int liczba = 0;

    while (!feof(plik)) {
        zawodnicy = realloc(zawodnicy, (liczba + 1) * sizeof(Zawodnik*));
        zawodnicy[liczba] = malloc(sizeof(Zawodnik));
        fscanf(plik, "%s %d", zawodnicy[liczba]->imie, &zawodnicy[liczba]->numerStartowy);
        printf("Wprowadź długość pierwszego skoku dla %s: ", zawodnicy[liczba]->imie);
        scanf("%d", &zawodnicy[liczba]->skok1);
        liczba++;
    }

    fclose(plik);

    qsort(zawodnicy, liczba, sizeof(Zawodnik*), porownaj1);

    for (int i = 0; i < liczba; i++) {
        printf("Wprowadź długość drugiego skoku dla %s: ", zawodnicy[i]->imie);
        scanf("%d", &zawodnicy[i]->skok2);
        zawodnicy[i]->sumaSkokow = zawodnicy[i]->skok1 + zawodnicy[i]->skok2;
    }

    qsort(zawodnicy, liczba, sizeof(Zawodnik*), porownaj2);

    plik = fopen("Wyniki.txt", "w");

    for (int i = 0; i < liczba; i++) {
        fprintf(plik, "%s %d %d %d %d\n", zawodnicy[i]->imie, zawodnicy[i]->numerStartowy, zawodnicy[i]->skok1, zawodnicy[i]->skok2, zawodnicy[i]->sumaSkokow);
        free(zawodnicy[i]);
    }

    free(zawodnicy);
    fclose(plik);

    return 0;
}