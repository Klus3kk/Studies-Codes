#include <stdio.h>

int main() {
    float dlugosc, szerokosc, wysokosc;
    printf("Podaj wymiary skrzynki w centymetrach:");
    scanf("%f%f%f", &dlugosc, &szerokosc, &wysokosc);
    printf("Objętość skrzynki wynosi %lf litrów", (dlugosc*szerokosc*wysokosc)/1000);
}