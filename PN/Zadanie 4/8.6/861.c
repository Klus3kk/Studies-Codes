#include <stdio.h>

void eratostenes(int numbers[], int n) {
    for (int i = 0; i < n; i++) {
        numbers[i] = 1;
    }

    numbers[0] = numbers[1] = 0; 

    for (int i = 2; i * i < n; i++) {
        if (numbers[i]) {
            for (int j = i * i; j < n; j += i) {
                numbers[j] = 0;
            }
        }
    }
}


int main() {
    int numbers[300];
    int n;

    printf("Podaj limit ciagu liczb pierwszych n: ");
    scanf("%d", &n);

    if(n > 0 && n < 299) {
        eratostenes(numbers,n);
        for(int i = 0; i < n; i++) {
            if(numbers[i]) {
                printf("%d ", i);
            }
        }
    } else {
        printf("\nZla liczba!");
        return 0;
    }
    return 0;
}