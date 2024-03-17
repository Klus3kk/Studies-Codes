#include <stdio.h>

int main() {
    int numbers[30],n,min, min2 = 10000000;

    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);

    if(n > 0 && n < 31) {
        printf("Podaj liczbe: ");
        scanf("%d", &numbers[0]);
        min = numbers[0];
        for(int i = 1; i < n; i++) {
            printf("Podaj liczbe: ");
            scanf("%d", &numbers[i]);
            if(min > numbers[i]) {
                min = numbers[i];
            }
        }
        for(int i = 0; i < n; i++) {
            if(min != numbers[i]) {
                if(min2 > numbers[i]) {
                    min2 = numbers[i];
                }
            }
        }
        printf("%d ", min2);
        
    } else {
        printf("\nZla liczba!");
        return 0;
    }
    return 0;
}