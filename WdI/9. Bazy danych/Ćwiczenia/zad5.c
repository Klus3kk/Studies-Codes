#include <stdio.h>
#include <string.h>

#define MaxS 100
#define MaxL 40

char Name[MaxS][MaxL];
int Hours[MaxS], Last;

int Query(void) {
    int j, Sum = 0;
    for (j = 0; j <= Last; j++) {
        if (Name[j][1] == 'a' || Name[j][1] == 'A') {
            Sum += Hours[j];
        }
    }
    return Sum;
}

int main(void) {
    FILE *file = fopen("zad5.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Can't open a file :c");
        return 1;
    }

    for (Last = -1; fscanf(file, "%s", &Name[++Last]) != EOF; Last++) {
        fscanf(file, "%d", &Hours[Last]);
    }

    fclose(file);

    printf("Total= %d\n", Query());
    return 0;
}
