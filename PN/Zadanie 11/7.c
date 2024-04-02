#include <stdio.h>

typedef struct {
    char typ;
    int numer;
    double wartosc;
} Pomiar;

int main() {
    Pomiar TP[4];

    FILE *file = fopen("PP.bin", "rb");
    fread(TP, sizeof(Pomiar), 4, file);

    for (int i = 0; i < 4; i++) {
        printf("%c %d %.2f\n", TP[i].typ, TP[i].numer, TP[i].wartosc);
    }

    fclose(file);

    return 0;
}