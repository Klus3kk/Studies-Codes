#include <stdio.h>

int main() {
    int wys;
    printf("Podaj rozmiar piramidy: ");
    scanf("%d", &wys);
    if (wys == 1) {
        printf("X\n");
    } else {
        int sr = wys / 2;
        for (int i = 0; i < wys; i++) {
            for (int j = 0; j < wys - i; j++) {
                printf(" ");
            }
            for (int j = 0; j < 2 * i + 1; j++) {
                printf("X");
            }
            printf("\n");
        }
    }
    return 0;
}
