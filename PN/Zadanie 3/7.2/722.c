#include <stdio.h>
#include <math.h>
int main() {
    int p = 2;
    for (int i = 1; i <= 8; i++) {
        printf("%d ", (int)pow(p,i));
    }
    return 0;
}