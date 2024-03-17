#include <stdio.h>

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
            if(numbers[i] % 2 == 0) {
                printf("%d ", numbers[i]);
            }
        }
    } else {
        printf("\nZla liczba!");
        return 0;
    }
    return 0;
}