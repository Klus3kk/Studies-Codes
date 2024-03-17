#include <stdio.h>

int main() {
    int wys, sr;
    printf("Podaj wysokosc krzyza: ");
    scanf("%d", &wys);
    sr = ((2 * wys) / 2) + 1;  
    for(int i = 1; i <= (2 * wys) + 1; i++) {
        for(int y = 1; y <= (2 * wys) + 1;y++) {
            if(i == sr) {
                printf("#");
            } else if (y == sr) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}