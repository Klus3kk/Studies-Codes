#include <stdio.h>

int main() {
    double numbers[30];
    int n;

    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);

    if(n > 0 && n < 31) {
        for(int i = 0; i < n; i++) {
            printf("Podaj liczbe: ");
            scanf("%lf", &numbers[i]);
        }
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                printf("%lf ", numbers[i]);
            }
        }
    } else {
        printf("\nZla liczba!");
        return 0;
    }
    return 0;
}