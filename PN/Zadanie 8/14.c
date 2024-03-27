#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Nazwa[64];
    char Producent[64];
    float Cena;
} Komputer;

void dodajKomputer(Komputer* TablicaKomputerow, int* index) {
    printf("Podaj nazwe komputera: ");
    scanf("%s", TablicaKomputerow[*index].Nazwa);
    printf("Podaj producenta komputera: ");
    scanf("%s", TablicaKomputerow[*index].Producent);
    printf("Podaj cene komputera: ");
    scanf("%f", &TablicaKomputerow[*index].Cena);
    (*index)++;
}

void szukajKomputera(Komputer* TablicaKomputerow, int index) {
    char Nazwa[64];
    printf("Podaj nazwe komputera: ");
    scanf("%s", Nazwa);
    for(int i = 0; i < index; i++) {
        if(strcmp(TablicaKomputerow[i].Nazwa, Nazwa) == 0) {
            printf("Nazwa: %s, Producent: %s, Cena: %.2f\n", TablicaKomputerow[i].Nazwa, TablicaKomputerow[i].Producent, TablicaKomputerow[i].Cena);
            return;
        }
    }
    printf("Komputer nie istnieje.\n");
}

void usunKomputer(Komputer* TablicaKomputerow, int* index) {
    char Nazwa[64];
    printf("Podaj nazwe komputera: ");
    scanf("%s", Nazwa);
    for(int i = 0; i < *index; i++) {
        if(strcmp(TablicaKomputerow[i].Nazwa, Nazwa) == 0) {
            for(int j = i; j < *index - 1; j++) {
                TablicaKomputerow[j] = TablicaKomputerow[j + 1];
            }
            (*index)--;
            return;
        }
    }
    printf("Komputer nie istnieje.\n");
}

void wyswietlKomputery(Komputer* TablicaKomputerow, int index) {
    for(int i = 0; i < index; i++) {
        printf("Nazwa: %s, Producent: %s, Cena: %.2f\n", TablicaKomputerow[i].Nazwa, TablicaKomputerow[i].Producent, TablicaKomputerow[i].Cena);
    }
}

int main() {
    Komputer* TablicaKomputerow = (Komputer*)malloc(100 * sizeof(Komputer));
    int index = 0;

    while(1) {
        char command;
        printf("Podaj polecenie: ");
        scanf(" %c", &command);

        switch(command) {
            case 'N':
            case 'n':
                dodajKomputer(TablicaKomputerow, &index);
                break;
            case 'S':
            case 's':
                szukajKomputera(TablicaKomputerow, index);
                break;
            case 'U':
            case 'u':
                usunKomputer(TablicaKomputerow, &index);
                break;
            case 'W':
            case 'w':
                wyswietlKomputery(TablicaKomputerow, index);
                break;
            case 'Q':
            case 'q':
                free(TablicaKomputerow);
                return 0;
        }
    }
}