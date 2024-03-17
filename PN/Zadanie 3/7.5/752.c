#include <stdio.h>
#include <math.h>

int silnia(int n) {
    if(n == 1) return 1;
    return n * silnia(n-1);
}


int main() {
    int n;
    printf("Podaj liczbe n: ");
    scanf("%d", &n);
    printf("%d", silnia(n));
    return 0;
}