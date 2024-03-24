#include <stdio.h>

void reszta(int n, int a) {
    if (a == 0) 
        printf("Nie istnieje");
    else {
        while(n - a >= 0) {
            n -= a;
        }
        printf("%d\n", n);
    }
}

int main() {
    int a,n;
    printf("Podaj liczbe (n) i jej dzielnik (a): ");
    scanf("%d%d", &n, &a);
    reszta(n,a);
    return 0;
}