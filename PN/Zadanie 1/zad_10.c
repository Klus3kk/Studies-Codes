#include <stdio.h>

int main() {
    float dlugosc, szerokosc, wysokosc;
    printf("Podaj wymiary skrzynki w centymetrach:");
    scanf("%f%f%f", &dlugosc, &szerokosc, &wysokosc);
    printf("Objętość skrzynki wynosi %f litrów\n", (dlugosc*szerokosc*wysokosc)/1000); // znak konwersji f
    printf("Objętość skrzynki wynosi %d litrów", (dlugosc*szerokosc*wysokosc)/1000); // znak konwersji d
}