#include <stdio.h>

int parzyste(int x) {
    while(x > 0) {
        if((x % 10) % 2 != 0) return 0;
        x = x / 10;
    }

    return 1;
}


int main() {
    int x;
    printf("Podaj liczbe x: ");
    scanf("%d", &x);
    printf("%d", parzyste(x));
    return 0;
}