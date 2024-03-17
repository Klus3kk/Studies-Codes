#include <stdio.h>

int sum_of_digits(long long number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

long long next_number(long long number) {
    long long divisor = 1;
    while ((number / divisor) % 10 == 9) {
        divisor *= 10;
    }
    return number + divisor;
}

int main() {
    int n;
    long long sum = 0;
    printf("Podaj n: ");
    scanf("%d", &n);
    while (n < 0) {
        printf("Podaj DODATNIE n: ");
        scanf("%d", &n);
    }

    int count = 0;
    for (long long i = 11111111111; count < n; i = next_number(i)) {
        if (sum_of_digits(i) == 100) {
            sum += i;
            count++;
        }
    }

    printf("%lld", sum); // it will only write one number because the second number will be too big

    return 0;
}