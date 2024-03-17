#include <stdio.h>

int main() {
    int w,s;
    printf("Podaj wysokosc i szerokosc: \n");
    scanf("%d%d", &w, &s);
    for (int i = 1; i <= w; i++) {
        for (int y = 1; y <= s; y++) {
            if (i == 1 || i == w) {
                printf("X");
            } else {
                if (y == 1 || y == s) {
                    printf("X");
                } else {    
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}