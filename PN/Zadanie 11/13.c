#include <stdio.h>
#include <string.h>

typedef struct {
    char nazwisko[50];
    char imie[50];
    int nrAlbumu;
} Student;

typedef struct {
    int nrAlbumu;
    int ocena;
} Ocena;

void wypiszPoNazwisku(Student* studenci, int n, Ocena* ocenyProg, int m, Ocena* ocenyFiz, int k) {
    char nazwisko[50];
    printf("Podaj nazwisko: ");
    scanf("%s", nazwisko);
    for (int i = 0; i < n; i++) {
        if (strcmp(studenci[i].nazwisko, nazwisko) == 0) {
            printf("%s %s\n", studenci[i].imie, studenci[i].nazwisko);
            for (int j = 0; j < m; j++) {
                if (ocenyProg[j].nrAlbumu == studenci[i].nrAlbumu) {
                    printf("Programowanie: %d\n", ocenyProg[j].ocena);
                }
            }
            for (int j = 0; j < k; j++) {
                if (ocenyFiz[j].nrAlbumu == studenci[i].nrAlbumu) {
                    printf("Fizyka: %d\n", ocenyFiz[j].ocena);
                }
            }
        }
    }
}

void wypiszPoNrAlbumu(Student* studenci, int n, Ocena* ocenyProg, int m, Ocena* ocenyFiz, int k) {
    int nrAlbumu;
    printf("Podaj numer albumu: ");
    scanf("%d", &nrAlbumu);
    for (int i = 0; i < n; i++) {
        if (studenci[i].nrAlbumu == nrAlbumu) {
            printf("%s %s\n", studenci[i].imie, studenci[i].nazwisko);
            for (int j = 0; j < m; j++) {
                if (ocenyProg[j].nrAlbumu == nrAlbumu) {
                    printf("Programowanie: %d\n", ocenyProg[j].ocena);
                }
            }
            for (int j = 0; j < k; j++) {
                if (ocenyFiz[j].nrAlbumu == nrAlbumu) {
                    printf("Fizyka: %d\n", ocenyFiz[j].ocena);
                }
            }
        }
    }
}

int main() {
    Student studenci[50];
    Ocena ocenyProg[50], ocenyFiz[50];
    int n, m, k;
    FILE *studenciFile = fopen("Studenci.txt", "r");
    FILE *progFile = fopen("Programowanie.txt", "r");
    FILE *fizFile = fopen("Fizyka.txt", "r");

    fscanf(studenciFile, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(studenciFile, "%s %s %d", studenci[i].nazwisko, studenci[i].imie, &studenci[i].nrAlbumu);
    }

    fscanf(progFile, "%d", &m);
    for (int i = 0; i < m; i++) {
        fscanf(progFile, "%d %d", &ocenyProg[i].nrAlbumu, &ocenyProg[i].ocena);
    }

    fscanf(fizFile, "%d", &k);
    for (int i = 0; i < k; i++) {
        fscanf(fizFile, "%d %d", &ocenyFiz[i].nrAlbumu, &ocenyFiz[i].ocena);
    }

    fclose(studenciFile);
    fclose(progFile);
    fclose(fizFile);
    char wybor;
    do {
        printf("N - wypisz po nazwisku\nA - wypisz po numerze albumu\nQ - koniec programu\n");
        scanf(" %c", &wybor);
        switch (wybor) {
            case 'N':
                wypiszPoNazwisku(studenci, n, ocenyProg, m, ocenyFiz, k);
                break;
            case 'A':
                wypiszPoNrAlbumu(studenci, n, ocenyProg, m, ocenyFiz, k);
                break;
        }
    } while (wybor != 'Q');
    return 0;
}