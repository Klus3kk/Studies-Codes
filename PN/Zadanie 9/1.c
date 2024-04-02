#include <stdio.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Cannot open file\n");
        return 1;
    }

    char target = 'a';  // The chosen character
    int count = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (c == target) {
            count++;
        }
    }

    fclose(file);

    printf("The character '%c' appears %d times\n", target, count);

    return 0;
}