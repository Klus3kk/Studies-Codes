#include <stdio.h>
#include <math.h>

int main() {
    int n,x;
    printf("Podaj liczbe x oraz jej n-ta potege: ");
    scanf("%d%d", &x, &n);
    printf("%d", (int)pow(x,n));
    return 0;
}