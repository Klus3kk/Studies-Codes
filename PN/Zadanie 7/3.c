#include <stdio.h>
#include <stdlib.h>

struct Student {
    char imie[20];
    char nazwisko[20];
    int nr_albumu;
    float ocena;
};

int main() {
    int n, choice;
    printf("Podaj liczbe studentow: ");
    scanf("%d", &n);
    struct Student array[n];

    for(int i = 0; i < n; i++) {
        printf("Podaj imie, nazwisko, nr albumu i ocene: ");
        scanf("%s %s %d %f", array[i].imie, array[i].nazwisko, &array[i].nr_albumu, &array[i].ocena);
    }

    for(int i = 0; i < n; i++) {
        printf("%s %s %d %f\n", array[i].imie, array[i].nazwisko, array[i].nr_albumu, array[i].ocena);
    }

    while(1) {
        printf("1. Modyfikuj dane\n2. Wyznacz srednia, maksymalne, minimalne oceny dla studentow\n3. Usun dane o grupie studentow\n4. Zakoncz program\n");
        int result = scanf("%d", &choice);
        if(result != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("Niepoprawny wybor\n");
            continue;
        }
        switch(choice) {
            case 1:
                int nr, choice2;
                printf("Podaj numer studenta: ");
                scanf("%d", &nr);
                if(nr >= n) {
                    printf("Nie ma takiego studenta\n");
                    break;
                }
                printf("Co chcesz zmienic?\n1. Imie\n2. Nazwisko\n3. Nr albumu\n4. Ocena\n");
                scanf("%d", &choice2);
                switch(choice2) {
                    case 1:
                        printf("Podaj nowe imie: ");
                        scanf("%s", array[nr].imie);
                        break;
                    case 2:
                        printf("Podaj nowe nazwisko: ");
                        scanf("%s", array[nr].nazwisko);
                        break;
                    case 3:
                        printf("Podaj nowy nr albumu: ");
                        scanf("%d", &array[nr].nr_albumu);
                        break;
                    case 4:
                        printf("Podaj nowa ocene: ");
                        scanf("%f", &array[nr].ocena);
                        break;
                }
                break;
            case 2:
                float sum = 0, max = 0, min = 6;
                for(int i = 0; i < n; i++) {
                    sum += array[i].ocena;
                    if(array[i].ocena > max) {
                        max = array[i].ocena;
                    }
                    if(array[i].ocena < min) {
                        min = array[i].ocena;
                    }
                }
                printf("Srednia: %f\nMaksymalna: %f\nMinimalna: %f\n", sum / n, max, min);
                break;
            case 3:
                printf("Podaj numer studenta: ");
                int nr2;
                scanf("%d", &nr2);
                for(int i = nr2; i < n - 1; i++) {
                    array[i] = array[i + 1];
                }
                n--;
                break;
            case 4:
                printf("Koniec programu\n");
                return 0;
                break;
            default:
                printf("Niepoprawny wybor\n");
                return 0;
                break;
        }
    }

    return 0;
}