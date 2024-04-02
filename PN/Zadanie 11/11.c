#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file = fopen("Eden.txt", "r");
    if (file == NULL) {
        printf("Nie mozna otworzyc pliku.\n");
        return 1;
    }

    int counts[26] = {0};
    int total = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        c = tolower(c);
        if (c >= 'a' && c <= 'z') {
            counts[c - 'a']++;
            total++;
        }
    }

    fclose(file);

    for (int i = 0; i < 26; i++) {
        double percentage = (double)counts[i] / total * 100;
        printf("%c : %d => %.1f%%\n", 'a' + i, counts[i], percentage);

        printf("%c | ", 'a' + i);
        for (int j = 0; j < counts[i] / 1000; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}