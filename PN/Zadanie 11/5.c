#include <stdio.h>

int main() {
    int counts[9] = {0};
    int values[9] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    char symbols[9] = {'c', 't', 'f', 'd', 'q', 'h', 'K', 'D', 'F'};
    int total = 0;

    FILE *file = fopen("coins.txt", "r");

    char c;
    while ((c = getc(file)) != EOF) {
        for (int i = 0; i < 9; i++) {
            if (c == symbols[i]) {
                total += values[i];
                counts[i]++;
                break;
            }
        }
    }

    printf("Total amount: %d.%02d\n", total / 100, total % 100);
    for (int i = 0; i < 9; i++) {
        printf("Number of '%c' coins: %d\n", symbols[i], counts[i]);
    }

    fclose(file);

    return 0;
}