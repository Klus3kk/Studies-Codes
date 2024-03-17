#include <stdio.h>

int main() {
    int wys,szer;
    printf("Podaj wysokosc i szerokosc: \n");
    scanf("%d%d", &wys, &szer);
    for (int i = 1; i <= wys; i++) {
        for (int y = 1; y <= szer; y++) {
            printf("X");
        }
        printf("\n");
    }
    return 0;
}