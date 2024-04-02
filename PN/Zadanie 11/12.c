#include <stdio.h>
#include <string.h>

typedef struct {
    char miasto[50];
    char ulica[50];
    int nrDomu;
    int nrMieszkania;
} Adres;

Adres Nowy(char miasto[]) {
    Adres adres;
    strcpy(adres.miasto, miasto);
    strcpy(adres.ulica, "X");
    adres.nrDomu = 0;
    adres.nrMieszkania = 0;
    return adres;
}

Adres NowyWithDetails(char miasto[], char ulica[], int nrd, int nrm) {
    Adres adres;
    strcpy(adres.miasto, miasto);
    strcpy(adres.ulica, ulica);
    adres.nrDomu = nrd;
    adres.nrMieszkania = nrm;
    return adres;
}

Adres NowyFromAdres(Adres adres) {
    Adres nowyAdres;
    strcpy(nowyAdres.miasto, adres.miasto);
    strcpy(nowyAdres.ulica, adres.ulica);
    nowyAdres.nrDomu = adres.nrDomu;
    nowyAdres.nrMieszkania = adres.nrMieszkania + 1000;
    return nowyAdres;
}

void Opis(Adres adres) {
    printf("%s, %s, %d, %d\n", adres.miasto, adres.ulica, adres.nrDomu, adres.nrMieszkania);
}

int main() {
    Adres A1 = Nowy("Gniezno");
    Adres A2 = NowyWithDetails("Koszalin", "Dobra", 15, 3);
    Adres A3 = NowyFromAdres(A2);

    Opis(A1);
    Opis(A2);
    Opis(A3);

    return 0;
}