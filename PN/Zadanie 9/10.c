#include <stdio.h>
#include <string.h>

#define MAX_COLS 100
#define MAX_ROWS 100

int main() {
    FILE *inputFile = fopen("input4.txt", "r");
    FILE *outputFile = fopen("output4.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[256];
    int numbers[MAX_ROWS][MAX_COLS] = {0};
    int rowCount = 0, colCount[MAX_ROWS] = {0};

    while (fgets(line, sizeof(line), inputFile)) {
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            numbers[rowCount][colCount[rowCount]++] = atoi(token);
            token = strtok(NULL, " \t\n");
        }
        rowCount++;
    }

    fprintf(outputFile, "SUMA\n");
    for (int i = 0; i < rowCount; i++) {
        int sum = 0;
        for (int j = 0; j < colCount[i]; j++) {
            fprintf(outputFile, "| %d ", numbers[i][j]);
            sum += numbers[i][j];
        }
        fprintf(outputFile, "| %d\n", sum);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}