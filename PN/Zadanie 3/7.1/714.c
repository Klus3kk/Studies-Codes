#include <stdio.h>

int main() {
    int s;
    printf("Podaj rozmiar A: ");
    scanf("%d", &s);
    if (s == 1) {
        printf("A\n");
    } else {
        int sr = s / 2;
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s - i; j++) {
                printf(" ");
            }
            for (int j = 0; j < 2 * i + 1; j++) {
                if (i == sr || (j == 0 || j == 2 * i)) {
                    printf("A");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
