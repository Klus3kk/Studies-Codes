#include <stdio.h>

void fib(int n) { // 0 1 1 2 3 5
    int f1 = 0, f2 = 1,temp;
    while(n > f2) {
        f2 += f1;
        temp = f2 - f1;
        if(temp < n) {
            f1 = temp;
        } else {
            break;
        }
    }
    printf("%d", f1);
}


int main() {
    int n = 150;
    fib(n);
    return 0;
}