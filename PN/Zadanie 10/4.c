#include <stdio.h>
#include <string.h>

#define MAX_PRACOWNICY 10


struct Pracownik {
    char imie[20];
    char nazwisko[20];
    int pensja;
    double procent;
};

struct Pracownik pracownicy[10];
int liczba_pracownikow = 0;

void nowy_pracownik() {
    if (liczba_pracownikow >= MAX_PRACOWNICY) {
        printf("Brak miejsca na nowego pracownika\n");
        return;
    }
    printf("Podaj imie, nazwiwsko, pensje i procent: ");
    scanf("%s %s %d %lf", pracownicy[liczba_pracownikow].imie, pracownicy[liczba_pracownikow].nazwisko, &pracownicy[liczba_pracownikow].pensja, &pracownicy[liczba_pracownikow].procent);
    liczba_pracownikow++;
}


void nowa_pensja() {
    char nazwisko[20];
    int nowa_pensja;
    printf("Podaj nazwisko i nowa pensje: ");
    scanf("%s %d", nazwisko, &nowa_pensja);
    for(int i = 0; i < liczba_pracownikow; i++) {
        if (strcmp(pracownicy[i].nazwisko, nazwisko) == 0) {
            pracownicy[i].pensja = nowa_pensja;
            return;
        }
    }
    printf("Nie znaleziono pracownika\n");
}


void nowy_procent() {
    char nazwisko[20];
    double nowy_procent;
    printf("Podaj nazwisko i nowy procent: ");
    scanf("%s %lf", nazwisko, &nowy_procent);
    for(int i = 0; i < liczba_pracownikow; i++) {
        if (strcmp(pracownicy[i].nazwisko, nazwisko) == 0) {
            pracownicy[i].procent = nowy_procent;
            return;
        }
    }
    printf("Nie znaleziono pracownika\n");
}

void wyplata() {
    char nazwisko[20];
    printf("Podaj nazwisko: ");
    scanf("%s", nazwisko);
    for(int i = 0; i < liczba_pracownikow; i++) {
        if (strcmp(pracownicy[i].nazwisko, nazwisko) == 0) {
            printf("Wyplata: %lf\n", pracownicy[i].pensja + pracownicy[i].pensja * pracownicy[i].procent);
            return;
        }
    }
    printf("Nie znaleziono pracownika\n");
}




int main() {
    char opcja;
    while(1) {
        fflush(stdin);
        printf("Podaj opcje: ");
        scanf("%c", &opcja);
        switch (opcja) {
            case 'N':
                nowy_pracownik();
                break;
            case 'P':
                nowa_pensja();
                break;
            case 'R':
                nowy_procent();
                break;
            case 'W':
                wyplata();
                break;
            case 'K':
                printf("Koniec\n");
                return 0;
                break;
            default:
                printf("Niepoprawna opcja\n");
                return 0;
                break;
        
        }
    }
    return 0;
}