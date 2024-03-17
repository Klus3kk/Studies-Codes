#include <stdio.h>

int cyfry(int n) {
    int k = 0;
    while(n > 0) {
        k += n % 10;
        n = n / 10;
    }

    return k;
}



int main() {
    int n;
    printf("Podaj liczbe: ");
    scanf("%d", &n);
    printf("%d",cyfry(n));
    return 0;
}