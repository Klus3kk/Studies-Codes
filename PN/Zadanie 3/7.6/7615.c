#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void replaceWithSquares(int n) {
    int k = 0, i = 0;
    int numbers[100]; 
    while(n > 0 && i < 100) {
        k = n % 10;
        n = n / 10;
        numbers[i] = (k + k * k) % 10;
        i++;
    }
    for(int j = i - 1; j >= 0; j--) {
        printf("%d", numbers[j]);
    }
}

int main() {
    int n;

    printf("Podaj liczbe: ");
    scanf("%d", &n);

    replaceWithSquares(n);

    return 0;
}
