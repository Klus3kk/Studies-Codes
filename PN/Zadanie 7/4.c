#include <stdio.h>
#include <string.h>

typedef struct {
    char tytul[50];
    char wykonawca[50];
    int rok;
    int numer_katalogowy;
    char gatunek[50];
} Plyta;

Plyta wczytajPlyte() {
    Plyta p;
    printf("Podaj tytul plyty: ");
    scanf("%s", p.tytul);
    printf("Podaj wykonawce plyty: ");
    scanf("%s", p.wykonawca);
    printf("Podaj rok wydania plyty: ");
    scanf("%d", &p.rok);
    printf("Podaj numer katalogowy plyty: ");
    scanf("%d", &p.numer_katalogowy);
    printf("Podaj gatunek plyty: ");
    scanf("%s", p.gatunek);
    return p;
}

void wyswietlPlyte(Plyta p) {
    printf("Tytul: %s\n", p.tytul);
    printf("Wykonawca: %s\n", p.wykonawca);
    printf("Rok wydania: %d\n", p.rok);
    printf("Numer katalogowy: %d\n", p.numer_katalogowy);
    printf("Gatunek: %s\n", p.gatunek);
}

int porownaj(Plyta p1, Plyta p2) {
    return strcmp(p1.tytul, p2.tytul);
}

void sortujPlyty(Plyta katalog[100], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(porownaj(katalog[j], katalog[j+1]) > 0) {
                Plyta temp = katalog[j];
                katalog[j] = katalog[j+1];
                katalog[j+1] = temp;
            }
        }
    }
}

int main() {
    Plyta katalog[100];
    int n = 0;
    int choice;
    while(1) {
        printf("1. Dodaj plyte\n2. Wyswietl plyty\n3. Sortuj plyty\n4. Zakoncz program\n");
        int result = scanf("%d", &choice);
        if(result != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("Niepoprawny wybor\n");
            continue;
        }
        switch(choice) {
            case 1:
                if(n < 100) {
                    katalog[n] = wczytajPlyte();
                    n++;
                } else {
                    printf("Katalog jest pelny\n");
                }
                break;
            case 2:
                for(int i = 0; i < n; i++) {
                    wyswietlPlyte(katalog[i]);
                }
                break;
            case 3:
                sortujPlyty(katalog, n);
                break;
            case 4:
                return 0;
            default:
                printf("Niepoprawny wybor\n");
        }
    }
}