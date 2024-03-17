#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Podaj n: ");
    scanf("%d", &n);
    while(n < 0) {
        printf("Podaj DODATNIE n: ");
        scanf("%d", &n);
    }
    for(int i = 1; i <= n; i++) {
        sum += 2*i - 1;
    }
    printf("%d", sum);
    return 0;
}