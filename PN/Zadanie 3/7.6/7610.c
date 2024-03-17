#include <stdio.h>
#include <math.h>

int main() {
    int a,b;
    printf("Podaj liczby a i b: ");
    scanf("%d%d", &a, &b);
    for(int i = a; i <= b; i++) {
        double sqrt_number = sqrt(i);
        if (i % 10 == (int)(sqrt_number) % 10 && (int)sqrt_number == sqrt_number) {
            printf("%d\n", i);
        } 
    }
    return 0;
}
