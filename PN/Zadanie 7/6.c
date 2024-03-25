#include <stdio.h>

int silnia(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * silnia(n - 1);
    }
}

int main() {
    int n;
    printf("Podaj liczbe: ");
    scanf("%d", &n);
    printf("%d\n", silnia(n));
    return 0;
}