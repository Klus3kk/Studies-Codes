#include <stdio.h>
#include <math.h>

int nwd(int a, int b) {
    if(b != 0) return nwd(b, a%b);
    return a;
}


int main() {
    int a,b;
    printf("Podaj liczbe a i b: ");
    scanf("%d%d", &a, &b);
    printf("%d", nwd(a,b));
    return 0;
}