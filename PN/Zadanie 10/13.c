#include <stdio.h>

int main() {
    FILE *plikWejsciowy = fopen("Lili.txt", "r");
    FILE *plikParzyste = fopen("Pa.txt", "w");
    FILE *plikNieparzyste = fopen("NiePa.txt", "w");
    int liczba;

    if (plikWejsciowy == NULL || plikParzyste == NULL || plikNieparzyste == NULL) {
        printf("Nie moge otworzyc pliku\n");
        return 1;
    }

    while (fscanf(plikWejsciowy, "%d", &liczba) == 1) {
        if (liczba % 2 == 0) {
            fprintf(plikParzyste, "%d ", liczba);
        } else {
            fprintf(plikNieparzyste, "%d ", liczba);
        }
    }

    fclose(plikWejsciowy);
    fclose(plikParzyste);
    fclose(plikNieparzyste);

    return 0;
}