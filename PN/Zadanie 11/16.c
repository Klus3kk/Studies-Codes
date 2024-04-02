#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// idk whats wrong with this code, it should work but it doesnt
bool check(unsigned int x) {
    bool result = ((x >> 28) & 0xF) == 0xB && (x & 0xF) == 0x2;
    printf("Check result for %u: %s\n", x, result ? "True" : "False");
    return result;
}

int main() {
    int W, K;
    printf("Podaj W i K: ");
    scanf("%d%d", &W, &K);

    unsigned int **array = malloc(W * sizeof(unsigned int *));
    for (int i = 0; i < W; i++) {
        array[i] = malloc(K * sizeof(unsigned int));
        for (int j = 0; j < K; j++) {
            scanf("%u", &array[i][j]);
        }
    }

    for (int j = 0; j < K; j++) {
        if (check(array[0][j])) {
            for (int i = 1; i < W; i++) {
                printf("%u ", array[i][j]);
            }
            printf("\n");
        }
    }

    for (int i = 0; i < W; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
