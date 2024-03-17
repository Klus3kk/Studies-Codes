#include <stdio.h>

// Funkcja sprawdzająca, czy liczba jest pierwsza
int is_prime(int number) {
    if (number < 2) return 0;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, sum = 0;
    printf("Podaj n: ");
    scanf("%d", &n);
    while (n < 0) {
        printf("Podaj DODATNIE n: ");
        scanf("%d", &n);
    }

    int count = 0;
    for (int i = 2; count < n; i++) {
        if (is_prime(i)) {
            sum += i;
            count++;
        }
    }

    printf("%d", sum);

    return 0;
}
