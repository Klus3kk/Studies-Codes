#include <stdio.h>

void silnia(int n) {
    for(int i = n - 1; i > 1; i--) {
        n *= i;
    }
    printf("%d", n);
}


int main() {
    int n;
    printf("Podaj liczbe: ");
    scanf("%d", &n);
    silnia(n);
    return 0;
}