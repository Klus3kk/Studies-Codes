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
    int a,b;
    printf("Podaj liczby a i b: ");
    scanf("%d%d", &a, &b);
    for(int i = a; i <= b; i++) {
        if(palindrom(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}