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


void blizniacze(int a) {
    for(int i = 1; i <= a; i++) {
        if(is_prime(i)) {
            for(int j = 2; j <= a/2; j++) {
                if(is_prime(j)) {
                    if(abs(i-j) == 2) {
                        printf("%d %d\n", i, j);
                    }
                }
            }
        }
    }
}


int main() {
    int a;
    printf("Podaj liczbe a (zakres maksymalny):");
    scanf("%d", &a);
    blizniacze(a);
    return 0;
}