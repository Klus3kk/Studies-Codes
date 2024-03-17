#include <stdio.h>

int main() {
    int n[10];
    for(int i = 0; i < 10; i++) {
        printf("Podaj liczbe: \n");
        scanf("%d", &n[i]);
    }
    printf("\n");
    for(int i = 9; i >= 0; i--) {
        printf("%d ", n[i]);
    }
    return 0;
}