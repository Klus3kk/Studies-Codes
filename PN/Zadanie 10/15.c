#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int przetworzIP(const char *adres) {
    unsigned int wynik = 0;
    int skladnik = 0;
    char c;

    for (int i = 0; (c = adres[i]) != '\0'; i++) {
        if (c >= '0' && c <= '9') {
            skladnik = skladnik * 10 + (c - '0');
            if (skladnik > 255) {
                printf("Niepoprawny adres IP\n");
                exit(1);
            }
        } else if (c == '.') {
            wynik = (wynik << 8) | skladnik;
            skladnik = 0;
        } else {
            printf("Niepoprawny adres IP\n");
            exit(1);
        }
    }

    wynik = (wynik << 8) | skladnik;

    return wynik;
}

int main() {
    char adres[16];

    printf("Podaj adres IP: ");
    scanf("%15s", adres);

    unsigned int wynik = przetworzIP(adres);

    printf("Adres binarny: %08X\n", wynik);

    return 0;
}