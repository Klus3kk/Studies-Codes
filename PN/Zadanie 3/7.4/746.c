#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Podaj n: ");
    scanf("%d", &n);
    while(n < 0) {
        printf("Podaj DODATNIE n: ");
        scanf("%d", &n);
    }
    int count = 0;
    for (int i = 1; count < n; i++) {
        int last_digit = i % 100; 
        if (last_digit == 31 || last_digit == 62 || last_digit == 17) {
            sum += i;
            count++;
        }
    }

    printf("%d", sum);

    return 0;
}
