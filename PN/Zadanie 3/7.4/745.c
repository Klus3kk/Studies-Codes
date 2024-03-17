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
        int last_digit = i % 10; 
        if (last_digit == 1 || last_digit == 2 || last_digit == 7) {
            sum += i;
            count++;
        }
    }

    printf("%d", sum);

    return 0;
}
