#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LICZBA_LITER 27
#define LICZBA_LICZB 4

void kodujDekoduj(char *plikWejsciowy, char *plikWyjsciowy, int kartaSzyfrujaca[LICZBA_LITER][LICZBA_LICZB], int koduj) {
    FILE *wejscie = fopen(plikWejsciowy, "r");
    FILE *wyjscie = fopen(plikWyjsciowy, "w");
    char c;

    while ((c = fgetc(wejscie)) != EOF) {
        int indeks = (c == ' ') ? 26 : (c - 'a');
        int kod = (koduj) ? kartaSzyfrujaca[indeks][0] : kartaSzyfrujaca[indeks][1];
        fputc(kod, wyjscie);
    }

    fclose(wejscie);
    fclose(wyjscie);
}

int main() {
    int kartaSzyfrujaca[LICZBA_LITER][LICZBA_LICZB];
    char kierunek[10];
    char plikWejsciowy[50];
    char plikWyjsciowy[50];

    FILE *plik = fopen("S.bin", "rb");
    if (plik == NULL) {
        printf("Nie moge otworzyc pliku S.bin\n");
        return 1;
    }
    fread(kartaSzyfrujaca, sizeof(int), LICZBA_LITER * LICZBA_LICZB, plik);
    fclose(plik);

    printf("Podaj kierunek przeksztalcenia (kodowanie/dekodowanie): ");
    scanf("%s", kierunek);

    printf("Podaj nazwe pliku wejsciowego: ");
    scanf("%s", plikWejsciowy);

    printf("Podaj nazwe pliku wyjsciowego: ");
    scanf("%s", plikWyjsciowy);

    if (strcmp(kierunek, "kodowanie") == 0) {
        kodujDekoduj(plikWejsciowy, plikWyjsciowy, kartaSzyfrujaca, 1);
    } else if (strcmp(kierunek, "dekodowanie") == 0) {
        kodujDekoduj(plikWejsciowy, plikWyjsciowy, kartaSzyfrujaca, 0);
    } else {
        printf("Nieznany kierunek przeksztalcenia: %s\n", kierunek);
        return 1;
    }

    return 0;
}