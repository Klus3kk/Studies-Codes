#include <stdio.h>

#define MAX_COLS 100
#define MAX_ROWS 100

int main() {
    FILE *inputFile = fopen("input2.txt", "r");
    FILE *outputFile = fopen("output2.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int numbers[MAX_ROWS][MAX_COLS] = {0};
    int rowCount = 0, colCount = 0, maxColCount = 0;
    int num;

    while (fscanf(inputFile, "%d", &num) == 1) {
        numbers[rowCount][colCount++] = num;
        if (fgetc(inputFile) == '\n') {
            if (colCount > maxColCount) {
                maxColCount = colCount;
            }
            rowCount++;
            colCount = 0;
        }
    }

    // Handle the last line if it doesn't end with a newline
    if (colCount > 0 && colCount > maxColCount) {
        maxColCount = colCount;
        rowCount++;
    }

    int sum[MAX_COLS] = {0};
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < maxColCount; j++) {
            sum[j] += numbers[i][j];
        }
    }

    fprintf(outputFile, "Suma: ");
    for (int j = 0; j < maxColCount; j++) {
        fprintf(outputFile, "%d ", sum[j]);
    }
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Srednia: ");
    for (int j = 0; j < maxColCount; j++) {
        fprintf(outputFile, "%.1f ", (float)sum[j] / rowCount);
    }
    fprintf(outputFile, "\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}