#include <stdio.h>

int main() {
    for(int i = 1; i < 6; i++) {
        for(int y = 0; y < i; y++) {
            printf("O");
        }
        printf("\n");
    }
    return 0;
}