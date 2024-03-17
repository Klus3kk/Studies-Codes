#include <stdio.h>

int palindrom(int num) {
    int reversed = 0;
    int original = num;
    
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    
    return original == reversed;
}

int main() {
    int n;
    printf("Podaj liczbe: ");
    scanf("%d", &n);
    
    printf("%d\n", palindrom(n));
    
    return 0;
}
