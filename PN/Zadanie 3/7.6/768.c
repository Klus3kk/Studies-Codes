#include <stdio.h>

int odwrotnie(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}



int main() {
    int n;
    printf("Podaj liczbe: ");
    scanf("%d", &n);
    printf("%d",odwrotnie(n));
    return 0;
}