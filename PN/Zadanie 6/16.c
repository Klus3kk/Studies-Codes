#include <stdio.h>

int silnia(int n) {
    for(int i = n - 1; i > 1; i--) {
        n *= i;
    }
    return n;
}


void newton(int n, int k) {
    for(int i = 1; i <= k; i++) {
        printf("%d ", (silnia(n))/(silnia(i) * silnia(n-i)));
    }
}



int main() {
    int n,k;
    printf("Podaj n i k: ");
    scanf("%d%d", &n, &k);
    newton(n,k);
    return 0;
}