#include <stdio.h>
#include <stdbool.h>
// Hipoteza Goldbacha

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool goldbach_conjecture(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (is_prime(i) && is_prime(n - i)) {
            printf("%d = %d + %d\n", n, i, n - i);
            return true;
        }
    }
    return false;
}

int main() {
    int start, end;
    printf("Podaj początek zakresu liczb parzystych: ");
    scanf("%d", &start);
    printf("Podaj koniec zakresu liczb parzystych: ");
    scanf("%d", &end);

    if (start % 2 != 0) {
        printf("Podaj początek zakresu parzystych liczb!\n");
        return 1;
    }

    printf("Sprawdzanie hipotezy Goldbacha dla liczb parzystych od %d do %d:\n", start, end);
    for (int i = start; i <= end; i += 2) {
        if (!goldbach_conjecture(i)) {
            printf("Nie udało się znaleźć sumy dwóch liczb pierwszych dla liczby %d\n", i);
        }
    }

    return 0;
}
