#include <stdio.h>
int main(void) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if (x == y || x == z || y == z) {
        if (z == x && x== y) {
            printf("Trójkąt równoboczny");
        } else {
            printf("Trójkąt równoramienny");
        }
    }
}