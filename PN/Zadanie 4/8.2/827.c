#include <stdio.h>

int main() {
    int numbers[30],n,max = 0, max2 = 0, w = 0;

    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);

    if(n > 0 && n < 31) {
        for(int i = 0; i < n; i++) {
            printf("Podaj liczbe: ");
            scanf("%d", &numbers[i]);
            if(max < numbers[i]) {
                max = numbers[i];
            }
        }
        for(int i = 0; i < n; i++) {
            if(max != numbers[i]) {
                if(max2 < numbers[i]) {
                    max2 = numbers[i];
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(max2 == numbers[i]) {
                w++;
            }
        }
        printf("Liczba %d miala %d wystapien.", max2, w);
        
    } else {
        printf("\nZla liczba!");
        return 0;
    }
    return 0;
}