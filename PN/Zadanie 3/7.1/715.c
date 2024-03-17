#include <stdio.h>

int main() {
    int szer, wys, grubosc;
    printf("Podaj po kolei: szerokosc, wysokosc, grubosc litery L \n");
    scanf("%d%d%d", &szer, &wys, &grubosc);
    for(int i = 0; i < wys - grubosc; i++) {
        for(int z = 0; z < grubosc; z++) {
            printf("L");
        }
        printf("\n");
    }
    for(int i = 0; i < grubosc; i++) {
        for(int z = 0; z < szer; z++) {
            printf("L");
        }
        printf("\n");
    }
    return 0;
}