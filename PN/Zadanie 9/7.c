#include <stdio.h>

void conversion1(FILE *file) {
    int count[1000] = {0};
    int depth = 0;
    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        int new_depth = 0;
        while (line[new_depth] == '*') {
            new_depth++;
        }

        if (new_depth > depth) {
            count[new_depth - 1] = 0;
        }
        depth = new_depth;

        count[depth - 1]++;

        for (int i = 1; i < depth; i++) {
            printf("  ");
        }

        for (int i = 0; i < depth; i++) {
            printf("%d.", count[i]);
        }

        printf("%s", line + depth);
    }
}

void conversion2(FILE *file) {
    int count[5] = {0};
    int depth = 0;
    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        int new_depth = 0;
        while (line[new_depth] == '*') {
            new_depth++;
        }

        if (new_depth < depth) {
            for (int i = new_depth; i < depth; i++) {
                count[i] = 0;
            }
        }
        depth = new_depth;

        count[depth - 1]++;

        switch (depth) {
            case 1:
                printf("%c.", 'A' + count[0] - 1);
                break;
            case 2:
                printf("  %d.", count[1]);
                break;
            case 3:
                printf("    %c.", 'a' + count[2] - 1);
                break;
            case 4:
                printf("      (%d)", count[3]);
                break;
            case 5:
                printf("        (%c)", 'a' + count[4] - 1);
                break;
        }

        printf("%s", line + depth);
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    char choice;
    if (file == NULL) {
        printf("Cannot open file\n");
        return 1;
    }
    printf("Choose the conversion (1,2):");
    scanf("%c", &choice);
    switch(choice) {
        case '1':
            conversion1(file);
            break;
        case '2':
            conversion2(file);
            break;
        default:
            return 0;
    }

    fclose(file);
    return 0;
}