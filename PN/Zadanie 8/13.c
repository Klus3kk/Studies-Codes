#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Imie[16];
    char Nazwisko[64];
    long long Pesel;
} Pracownik;

void dodajPracownika(Pracownik* TablicaPracownikow, int* index) {
    printf("Podaj imie, nazwisko i PESEL pracownika: ");
    scanf("%s %s %lld", TablicaPracownikow[*index].Imie, TablicaPracownikow[*index].Nazwisko, &TablicaPracownikow[*index].Pesel);
    (*index)++;
}

void wyswietlPracownikow(Pracownik* TablicaPracownikow, int index) {
    for(int i = 0; i < index; i++) {
        printf("%s %s %lld\n", TablicaPracownikow[i].Imie, TablicaPracownikow[i].Nazwisko, TablicaPracownikow[i].Pesel);
    }
}

void sprawdzPracownika(Pracownik* TablicaPracownikow, int index) {
    long long Pesel;
    printf("Podaj PESEL pracownika: ");
    scanf("%lld", &Pesel);
    for(int i = 0; i < index; i++) {
        if(TablicaPracownikow[i].Pesel == Pesel) {
            printf("%s\n", TablicaPracownikow[i].Nazwisko);
            return;
        }
    }
    printf("Pracownik nie istnieje.\n");
}

void usunPracownika(Pracownik* TablicaPracownikow, int* index) {
    char Nazwisko[64];
    printf("Podaj nazwisko pracownika: ");
    scanf("%s", Nazwisko);
    for(int i = 0; i < *index; i++) {
        if(strcmp(TablicaPracownikow[i].Nazwisko, Nazwisko) == 0) {
            for(int j = i; j < *index - 1; j++) {
                TablicaPracownikow[j] = TablicaPracownikow[j + 1];
            }
            (*index)--;
            return;
        }
    }
    printf("Pracownik nie istnieje.\n");
}

void zapiszDoPliku(Pracownik* TablicaPracownikow, int index) {
    FILE* file = fopen("pracownicy.txt", "w");
    fprintf(file, "%d\n", index);
    for(int i = 0; i < index; i++) {
        fprintf(file, "%s %s %lld\n", TablicaPracownikow[i].Imie, TablicaPracownikow[i].Nazwisko, TablicaPracownikow[i].Pesel);
    }
    fclose(file);
}

void odczytajZPliku(Pracownik* TablicaPracownikow, int* index) {
    FILE* file = fopen("pracownicy.txt", "r");
    fscanf(file, "%d", index);
    for(int i = 0; i < *index; i++) {
        fscanf(file, "%s %s %lld", TablicaPracownikow[i].Imie, TablicaPracownikow[i].Nazwisko, &TablicaPracownikow[i].Pesel);
    }
    fclose(file);
}

int main() {
    Pracownik TablicaPracownikow[100];
    int index = 0;

    while(1) {
        char command;
        printf("Podaj polecenie: ");
        scanf(" %c", &command);

        switch(command) {
            case 'A':
                dodajPracownika(TablicaPracownikow, &index);
                break;
            case 'B':
                wyswietlPracownikow(TablicaPracownikow, index);
                break;
            case 'C':
                sprawdzPracownika(TablicaPracownikow, index);
                break;
            case 'D':
                usunPracownika(TablicaPracownikow, &index);
                break;
            case 'E':
                zapiszDoPliku(TablicaPracownikow, index);
                break;
            case 'F':
                odczytajZPliku(TablicaPracownikow, &index);
                break;
            default:
                return 0;
        }
    }
}