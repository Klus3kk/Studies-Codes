#include <stdio.h>

void perfect_number(int a) {
    int sp;
    for(int i = 1; i < a; i++) {
        sp = 0;
        for(int y = 1; y <= i/2; y++) {
            if(i%y == 0) {
                sp += y;
            }
        }
        if(sp == i) {
            printf("%d ", i);
        }
    }
}


int main() {
    int a;
    printf("Podaj a: ");
    scanf("%d", &a);
    perfect_number(a);
    return 0;
}