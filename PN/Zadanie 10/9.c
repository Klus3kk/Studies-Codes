#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* nazwa;
    int dzien;
} Zodiak;

int main() {
    Zodiak zodiaki[12] = {
        {"Koziorożec", 19}, {"Wodnik", 18}, {"Ryby", 20}, {"Baran", 19},
        {"Byk", 20}, {"Bliźnięta", 20}, {"Rak", 22}, {"Lew", 22},
        {"Panna", 22}, {"Waga", 22}, {"Skorpion", 21}, {"Strzelec", 21}
    };

    int dzienUrodzenia, miesiacUrodzenia;
    printf("Podaj numer dnia i miesiaca urodzenia: ");
    scanf("%d %d", &dzienUrodzenia, &miesiacUrodzenia);

    if (dzienUrodzenia > zodiaki[miesiacUrodzenia - 1].dzien) {
        miesiacUrodzenia++;
    }

    if (miesiacUrodzenia == 13) {
        miesiacUrodzenia = 1;
    }

    printf("Znak zodiaku: %s\n", zodiaki[miesiacUrodzenia - 1].nazwa);

    return 0;
}