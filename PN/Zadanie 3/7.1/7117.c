#include <stdio.h>
int main() {
    int h, m = 0;
    printf("Podaj rozmiar piramidy: ");
    scanf("%d", &h);
    for(int i = 1; i <= h; i++) {
        for(int y = 0; y < i; y++) {
            printf("%d ", m + (y*3));
        }
        printf("\n");
        m += 3;
    }
    return 0;
}