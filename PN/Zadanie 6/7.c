#include <stdio.h>

void eratostenes(int numbers[], int A, int B) {
    for (int i = 2; i * i <= B; i++) {
        for (int j = A/i * i; j <= B; j += i) {
            if (j >= A && j > i) {
                numbers[j - A] = 0;
            }
        }
    }
}

int main() {
    int A, B; 
    printf("Podaj A i B: ");
    scanf("%d%d", &A, &B);

    int n[B - A + 1]; 
    for (int i = 0; i <= B - A; i++) {
        n[i] = 1;
    }
    
    eratostenes(n, A, B); 

    printf("Liczby pierwsze w przedziale [%d, %d]: ", A, B);
    for (int i = A; i <= B; i++) { 
        if (n[i - A] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
