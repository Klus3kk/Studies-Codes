#include <stdio.h>

int main() {
    int h, l = 2;
    printf("Podaj rozmiar piramidy: ");
    scanf("%d", &h);
    for(int i = 1; i <= h; i++) {
        for(int y = 0; y < i; y++) {
            printf("%d ", l+y);
        }
        printf("\n");
        l *= 2;
    }
    return 0;
}