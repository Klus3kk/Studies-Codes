#include <stdio.h>

int main() {
    int ile, l = 0;
    printf("Podaj dlugosc ciagu: ");
    scanf("%d", &ile);
    for(int i = 1; i <= ile; i++) {
        printf("%d ", l);
        l += 3;
    }
    return 0;
}