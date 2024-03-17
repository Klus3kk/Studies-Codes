#include <stdio.h>
#include <math.h>

int main() {
    int number;

    printf("Podaj liczbę całkowitą: ");
    scanf("%d", &number);

    double sqrt_number = sqrt(number);

    if (number % 10 == (int)(sqrt_number) % 10 && (int)sqrt_number == sqrt_number) {
        printf("TAK\n");
    } else {
        printf("NIE\n");
    }

    return 0;
}
