#include <stdio.h>

int main() {
    int a = 21, b = 3;
    while(a != b) {
        a = a - 1;
        b = b + 1;
    }
    printf("%d\n%d", a,b);
    // a = 12, b = 12
    return 0;
}