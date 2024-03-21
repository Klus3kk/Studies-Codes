#include <stdio.h>

int sum_divisors(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}


void amicable_pairs(int a) {
    for (int i = 1; i <= a; i++) {
        int sp1 = sum_divisors(i); 
        if (sp1 > i && sp1 <= a) { 
            int sp2 = sum_divisors(sp1); 
            if (sp2 == i) { 
                printf("(%d, %d) ", i, sp1);
            }
        }
    }
}



int main() {
    int a;
    printf("Podaj a: ");
    scanf("%d", &a);
    amicable_pairs(a);
    return 0;
}