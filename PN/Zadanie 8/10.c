#include <stdio.h>
#include <stdlib.h>

int main() {
    int LR, RS;
    printf("Podaj dlugosc tablicy R: ");
    scanf("%d", &LR);
    printf("Podaj dlugosc tablicy S: ");
    scanf("%d", &RS);

    float* R = malloc(LR * sizeof(float));
    float* S = malloc(RS * sizeof(float));

    printf("Podaj elementy tablicy R: ");
    for(int i = 0; i < LR; i++) {
        scanf("%f", &R[i]);
    }

    printf("Podaj elementy tablicy S: ");
    for(int i = 0; i < RS; i++) {
        scanf("%f", &S[i]);
    }

    float* W = malloc((LR + RS) * sizeof(float));

    int i = 0, j = 0, k = 0;
    while(i < LR && j < RS) {
        if(R[i] <= S[j]) {
            W[k++] = R[i++];
        } else {
            W[k++] = S[j++];
        }
    }
    while(i < LR) {
        W[k++] = R[i++];
    }
    while(j < RS) {
        W[k++] = S[j++];
    }

    printf("Tablica W: ");
    for(int i = 0; i < LR + RS; i++) {
        printf("%f ", W[i]);
    }
    printf("\n");

    free(R);
    free(S);
    free(W);

    return 0;
}