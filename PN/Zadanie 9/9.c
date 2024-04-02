#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputFile = fopen("input3.txt", "r");
    FILE *outputFile = fopen("output3.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[256];
    int wordCount = 0;

    while (fgets(line, sizeof(line), inputFile)) {
        if (line[0] == ';') {
            continue;
        }

        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            wordCount++;
            token = strtok(NULL, " \t\n");
        }
    }

    fprintf(outputFile, "%d\n", wordCount);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}