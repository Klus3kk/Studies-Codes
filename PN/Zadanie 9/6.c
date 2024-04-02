#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " ");
        while (token != NULL) {
            int num = atoi(token);
            printf("%d ", abs(num));
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}