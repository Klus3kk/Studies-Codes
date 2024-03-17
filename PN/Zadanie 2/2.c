#include <stdio.h>
#include <math.h>

int main() {
    int a,b;
    scanf("%d%d", &a, &b);
    if (a != 0 && b != 0) {
        printf("%f",a*(a+b)/(pow((a+b),2)));
    }
    return 0;
}