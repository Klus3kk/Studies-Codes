#include <stdio.h>

int main() {
    int a = 81, b = 9;
    while(a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    printf("%d\n%d", a,b);
    // a = 9, b = 9 (NWD)
    return 0;
}