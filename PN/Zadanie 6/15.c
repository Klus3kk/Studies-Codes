#include <stdio.h>

int main() {
    int i, a, b, c;

    printf("Czwarta potega, ktora mozna wyrazic jako iloczyn trzech kolejnych liczb to:\n");

    for (i = 1; ; i++) {
        a = i;
        b = i + 1;
        c = i + 2;

        if (a * b * c == 24) {
            printf("%d * %d * %d = 24\n", a, b, c);
            break;
        }
    }

    return 0;
}
