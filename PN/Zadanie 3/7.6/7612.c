#include <stdio.h>

void replaceWithCubes(int number) {
    int temp = number;
    int result = 0;
    int position = 1;

    while (temp > 0) {
        int digit = temp % 10;
        result += digit * digit * digit * position;
        position *= 10;
        temp /= 10;
    }

    printf("ZADANIE 7.6.12: %d\n", result);
}


int main() {
    int x;
    printf("Podaj liczbe x: ");
    scanf("%d", &x);
    return 0;
}