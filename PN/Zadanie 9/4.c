#include <stdio.h>
#include <string.h>

#define N 500

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Cannot open file\n");
        return 1;
    }

    char line[N];
    char longest[N] = "";
    char shortest[N];
    memset(shortest, ' ', N - 1);  
    shortest[N - 1] = '\0';  

    while (fgets(line, N, file) != NULL) {
        line[strcspn(line, "\n")] = 0;  
        if (strlen(line) > strlen(longest)) {
            strcpy(longest, line);
        }
        if (strlen(line) < strlen(shortest)) {
            strcpy(shortest, line);
        }
    }

    fclose(file);

    printf("Longest line: %s\n", longest);
    printf("Shortest line: %s\n", shortest);

    return 0;
}