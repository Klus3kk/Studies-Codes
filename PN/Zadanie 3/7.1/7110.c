#include <stdio.h>

int main() {
    int wys;
    printf("Podaj rozmiar piramidy: ");
    scanf("%d", &wys);

    for (int i = 1; i <= wys; i++) {
        for (int j = 1; j <= wys; j++) {
            if (i == wys || j == 1 || j == i) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
