#include <stdio.h>

int main() {
    int x,y;
    printf("Podaj liczby x i y: ");
    scanf("%d%d", &x, &y);
    for (int a = x; a <= y; a++) {
        for (int b = a + 1; b <= y; b++) {
            for (int c = b + 1; c <= y; c++) {
                if (a * a + b * b == c * c) {
                    printf("(%d, %d, %d)\n", a, b, c);
                }
            }
        }
    }
    return 0;
}