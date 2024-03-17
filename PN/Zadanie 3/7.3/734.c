#include <stdio.h>
#include <math.h>
int main() {
    int l;
    printf("Wprowadz liczbe: ");
    scanf("%d", &l);
    while(l <= 0) {
        printf("\nWprowadz dodatnia liczbe! ");
        scanf("%d", &l);
    }
    printf("\n%lf",sqrt(l));
    return 0;
}