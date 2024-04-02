#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float szerokoscGeo;
    float dlugoscGeo;
    char nazwa[50];
} Miejscowosc;

int main() {
    FILE *plik = fopen("Polska.txt", "r");
    int liczbaMiejscowosci;
    fscanf(plik, "%d", &liczbaMiejscowosci);

    Miejscowosc miejscowosci[liczbaMiejscowosci];
    for (int i = 0; i < liczbaMiejscowosci; i++) {
        fscanf(plik, "%f %f %s", &miejscowosci[i].szerokoscGeo, &miejscowosci[i].dlugoscGeo, miejscowosci[i].nazwa);
    }
    fclose(plik);

    float xSzerokoscGeo, xDlugoscGeo;
    char opcja;
    do {
        printf("Podaj opcje: ");
        scanf(" %c", &opcja);

        switch (opcja) {
            case 'L':
                printf("Podaj szerokosc i dlugosc geograficzna miejsca X: ");
                scanf("%f %f", &xSzerokoscGeo, &xDlugoscGeo);
                break;
            case 'N':
                plik = fopen("Polnoc.txt", "w");
                for (int i = 0; i < liczbaMiejscowosci; i++) {
                    if (miejscowosci[i].szerokoscGeo > xSzerokoscGeo) {
                        fprintf(plik, "%s\n", miejscowosci[i].nazwa);
                    }
                }
                fclose(plik);
                break;
            case 'S':
                plik = fopen("Poludnie.txt", "w");
                for (int i = 0; i < liczbaMiejscowosci; i++) {
                    if (miejscowosci[i].szerokoscGeo < xSzerokoscGeo) {
                        fprintf(plik, "%s\n", miejscowosci[i].nazwa);
                    }
                }
                fclose(plik);
                break;
            case 'W':
                plik = fopen("Zachod.txt", "w");
                for (int i = 0; i < liczbaMiejscowosci; i++) {
                    if (miejscowosci[i].dlugoscGeo < xDlugoscGeo) {
                        fprintf(plik, "%s\n", miejscowosci[i].nazwa);
                    }
                }
                fclose(plik);
                break;
            case 'E':
                plik = fopen("Wschod.txt", "w");
                for (int i = 0; i < liczbaMiejscowosci; i++) {
                    if (miejscowosci[i].dlugoscGeo > xDlugoscGeo) {
                        fprintf(plik, "%s\n", miejscowosci[i].nazwa);
                    }
                }
                fclose(plik);
                break;
            case 'Q':
                printf("Koniec pracy.\n");
                break;
            default:
                printf("Nieznana opcja.\n");
        }
    } while (opcja != 'Q');

    return 0;
}