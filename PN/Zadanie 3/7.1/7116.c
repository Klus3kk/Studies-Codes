#include <stdio.h>

int main() {
    int h;
    printf("Podaj rozmiar piramidy: ");
    scanf("%d", &h);
    for(int i = 1; i <= h; i++) {
        for(int y = 1; y <= i; y++) {
            printf("%d ", y*i);
        }
        printf("\n");
    }
    return 0;
}