#include <stdio.h>

int multiply(int n, int m) {
    if (m == 0)
        return 0;
    else
        return n + multiply(n, m - 1);
}

int potega(int n, int a) {
    if (a == 0)
        return 1;
    else
        return multiply(n, potega(n, a - 1));
}

int main() {
    int a, n;
    printf("Podaj liczbe (n) i jej potege (a): ");
    scanf("%d%d", &n, &a);
    printf("%d\n", potega(n, a));
    return 0;
}