#include <stdio.h>

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    printf("T = %d", (5 + (4 + (3 + 2 * (m - n - 1)))) / ((((2 * (m + n + 1) - 3) - 4) - 5)));
    return 0;
}
