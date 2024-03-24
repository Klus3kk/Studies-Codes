#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


void mersenne(int a) {
    for(int i = 2; i <= a; i++) {
        if(is_prime(i)) {
            if((pow(2,i) - 1) > a) {
                break;
            } else {
                printf("%d\n", (int)pow(2,i) - 1);
            }
        }
    }
}

int main() {
    int a;
    printf("Podaj liczbe a (zakres maksymalny): ");
    scanf("%d", &a);
    mersenne(a);
    return 0;
}