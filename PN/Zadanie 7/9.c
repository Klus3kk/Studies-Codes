#include <stdio.h>

int sumDigits(int n) {
    if (n == 0)
        return 0;
    else
        return n % 10 + sumDigits(n / 10);
}

int main() {
    int n;
    printf("Podaj liczbe: ");
    scanf("%d", &n);
    printf("%d\n", sumDigits(n));
    return 0;
}