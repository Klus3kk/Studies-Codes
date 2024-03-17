#include <stdio.h>

int main() {
    int a;
    printf("Podaj dlugosc boku: ");
    scanf("%d", &a);
    for(int i = 1; i <= a; i++) {
        for(int y = 1; y <= a; y++) {
            printf("K");
        }
        printf("\n");
    }
    return 0;
}