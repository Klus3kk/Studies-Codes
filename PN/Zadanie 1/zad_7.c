#include <stdio.h>

int main() {
    int x, y, *p1 = &x, *p2;
    p2 = &y;
    scanf("%d%d", p1, p2);
    printf("x * y = %d", *p1 * *p2);
}