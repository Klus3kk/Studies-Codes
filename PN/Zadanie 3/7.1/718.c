#include <stdio.h>

int main() {
    int wys;
    printf("Podaj rozmiar A: ");
    scanf("%d", &wys);
    if (wys == 1) {
        printf("A\n");
    } else {
        int sr = wys / 2;
        for (int i = 0; i < wys; i++) {
            for (int j = 0; j < wys - i; j++) {
                printf(" ");
            }
            for (int j = 0; j < 2 * i + 1; j++) {
                if (i == wys - 1 || (j == 0 || j == 2 * i)) {
                    printf("A");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
