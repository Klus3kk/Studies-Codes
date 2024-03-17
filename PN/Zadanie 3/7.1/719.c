#include <stdio.h>

int main() {
    int wys;
    printf("Podaj rozmiar piramidy: ");
    scanf("%d", &wys);
    for(int i = 1; i <= wys; i++) {
        for(int y = 0; y < i; y++) {
            printf("X");
        }
        printf("\n");
    }
    return 0;
}