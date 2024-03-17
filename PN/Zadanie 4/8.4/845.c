#include <stdio.h>

int cyfry(int n) {
    int k = 0;
    while(n > 0) {
        k += n % 10;
        if(k % 2 != 0) return 0;
        n = n / 10;
    }

    return 1;
}


int main() {
    int numbers[30];
    int n;

    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);

    if(n > 0 && n < 31) {
        for(int i = 0; i < n; i++) {
            printf("Podaj liczbe: ");
            scanf("%d", &numbers[i]);
        }
        for(int i = 0; i < n; i++) {
            if(cyfry(numbers[i]) == 1) {
                printf("%d ", numbers[i]);
            }
        }
    } else {
        printf("\nZla liczba!");
        return 0;
    }
    return 0;
}