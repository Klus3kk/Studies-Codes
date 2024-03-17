#include <stdio.h>
int main(void) {
    int x = 13;
    // scanf("%d", &x);
    printf("%d\n", x/13*13 + x%13);
    return 0;
}