#include <stdio.h>

int main() {
    int numbers[30],n,min, w = 0;

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
            if(min == numbers[i]) {
                w++;
            }
        }
        printf("Liczba %d miala %d wystapien.", min, w);
        
    } else {
        printf("\nZla liczba!");
        return 0;
    }
    return 0;
}