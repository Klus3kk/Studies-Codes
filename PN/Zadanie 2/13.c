#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double sum = 0, mn = 1, l;
    printf("Wprowadz ilosc liczb: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("\nWprowadz liczbe: ");
        scanf("%lf", &l);
        sum += l;
        mn *= l;
    }
    printf("Srednia arytmetyczna: %lf \n Srednia geometryczna: %lf\n", sum/n,pow(mn, 1.0 / n));
    return 0;
}