#include <stdio.h>

int isAutomorphic(int n) {
    int square = n * n;
    while (n > 0) {
        if (n % 10 != square % 10)
            return 0;
        n /= 10;
        square /= 10;
    }
    return 1;
}

int main() {
    int a, b;
    printf("Podaj przedzial <a, b>: ");
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (isAutomorphic(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}