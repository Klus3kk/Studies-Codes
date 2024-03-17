#include <stdio.h>

int main() {
    int a = 1, b = 3;
    while(a < b) {
        a = 3 * a - 1;
        b = 2 * b + 1;
    }
    printf("%d\n%d", a,b);
    // a = 365, b = 255
    return 0;
}