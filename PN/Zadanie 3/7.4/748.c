#include <stdio.h>

// Funkcja do obliczania sumy cyfr liczby
int sum_of_digits(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
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
    for (int i = 1; count < n; i++) {
        if (sum_of_digits(i) % 2 == 0) {
            sum += i;
            count++;
        }
    }

    printf("%d", sum);

    return 0;
}
