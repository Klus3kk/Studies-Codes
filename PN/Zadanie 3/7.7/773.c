#include <stdio.h>

int main() {
    int a = 1000, b = 1;
    while(a > b) {
        a /= 2;
        b *= 2;
    }
    printf("%d\n%d", a,b);
    // a = 31, b = 32
    return 0;
}