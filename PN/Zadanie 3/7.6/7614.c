#include <stdio.h>

void replaceWithAddedNumbers(int number) {
    int temp = number;
    int result = 0;
    int position = 1;
    int adder = 1;

    while (temp > 0) {
        int digit = temp % 10;
        result += (digit + adder) * position;
        position *= 10;
        adder++;
        temp /= 10;
    }

    printf("ZADANIE 7.6.14: %d\n", result);
}


int main() {
    int x;
    printf("Podaj liczbe x: ");
    scanf("%d", &x);
    return 0;
}