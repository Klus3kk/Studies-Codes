#include <stdio.h>

int main() {
    int K[5] = {1,2,3,4,5}, temp;
    int n = sizeof(K)/sizeof(K[0]);
    for(int i = 0; i < n; i++) {
        printf("%d ", K[i]);
    }
    printf("\n");
    for(int i = 0; i < n/2; i++) {
        temp = K[i];
        K[i] = K[n-1-i];
        K[n-1-i] = temp;
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", K[i]);
    }
    return 0;
}