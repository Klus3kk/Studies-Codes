#include <stdio.h>

int main() {
    FILE *fileA = fopen("A.txt", "r");
    FILE *fileB = fopen("B.txt", "r");
    FILE *fileC = fopen("C.txt", "w");

    if (fileA == NULL || fileB == NULL || fileC == NULL) {
        printf("Nie mozna otworzyc pliku.\n");
        return 1;
    }

    int number;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            fscanf(fileA, "%d", &number);
        } else {
            fscanf(fileB, "%d", &number);
        }
        fprintf(fileC, "%d ", number);
    }

    fclose(fileA);
    fclose(fileB);
    fclose(fileC);

    return 0;
}