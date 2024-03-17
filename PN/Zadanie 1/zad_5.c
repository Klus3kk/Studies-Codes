#include <stdio.h>

int main() {
    int a;
    char c;
    scanf("%d", &a);
    fflush(stdin);
    scanf("%c", &c);
    printf("Liczba = %d, Znak = %c",a,c);
    return 0;
}