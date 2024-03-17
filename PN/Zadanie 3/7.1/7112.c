#include <stdio.h>

int main() {
    int wys;
    printf("Podaj wysokosc trojkata: ");
    scanf("%d", &wys);

    for(int i = 0; i < wys; i++) {
        for(int j = 0; j < wys - i - 1; j++) {
            printf(" ");
        }
        for(int j = 0; j <= i; j++) {
            if (i == wys - 1 || j == 0 || j == i) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
