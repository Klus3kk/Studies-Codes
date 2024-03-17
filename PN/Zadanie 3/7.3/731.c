#include <stdio.h>

int main() {
    int i;
    printf("Podaj liczbe: ");
    scanf("%d", &i);
    while(i <= 0) {
        printf("\nProsze podac dodatnia liczbe!\n");
        scanf("%d", &i);
    }
    return 0;
}