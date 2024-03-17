#include <stdio.h>

int cyfry(int n) {
    int k = 0;
    while(n > 0) {
        n = n / 10;
        k++;
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