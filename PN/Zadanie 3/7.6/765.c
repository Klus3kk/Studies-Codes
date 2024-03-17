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
    int max_palindrom = 0;
    
    for (int i = 2000000000; i < 2147483647; i++) {
        if (palindrom(i)) {
            max_palindrom = i;
        }
    }
    
    printf("%d\n", max_palindrom); // 2147447412
    
    return 0;
}
