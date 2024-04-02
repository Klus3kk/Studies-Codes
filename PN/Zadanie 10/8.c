#include <stdio.h>
#include <stdlib.h>

void option_A(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = -arr[i];
    }
}

void option_B(int *arr, int n) {
    for(int i = 1; i < n; i++) {
        arr[i] *= arr[0];
    }
}

int main() {
    int n;
    do {
        printf("Podaj n (wieksze od 25): ");
        scanf("%d", &n);
    } while(n <= 25);

    int *T = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        printf("Podaj T[%d]: ", i);
        scanf("%d", &T[i]);
    }

    char option;
    printf("Podaj opcje (A lub B): ");
    scanf(" %c", &option);
    if(option == 'A') {
        option_A(T, n);
    } else if(option == 'B') {
        option_B(T, n);
    }

    printf("PrzeksztaLcona tablica: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");

    free(T);
    return 0;
}