#include <stdio.h>
#include <string.h>

typedef struct {
    char NazwaTowaru[50];
    int LiczbaSztuk;
    float Cena1Sztuki;
} Towar;

int main() {
    Towar TablicaTowarow[50];
    int index = 0;

    while(1) {
        char command;
        printf("Podaj polecenie: ");
        fflush(stdin);
        scanf("%c", &command);

        if(command == 'N' || command == 'n') {
            printf("Podaj nazwe towaru: ");
            scanf("%s", TablicaTowarow[index].NazwaTowaru);
            printf("Podaj liczbe sztuk: ");
            scanf("%d", &TablicaTowarow[index].LiczbaSztuk);
            printf("Podaj cene jednej sztuki: ");
            scanf("%f", &TablicaTowarow[index].Cena1Sztuki);
            index++;
        } else if(command == 'W' || command == 'w') {
            for(int i = 0; i < index; i++) {
                printf("%s %d %f\n", TablicaTowarow[i].NazwaTowaru, TablicaTowarow[i].LiczbaSztuk, TablicaTowarow[i].Cena1Sztuki);
            }
        } else if(command == 'R' || command == 'r') {
            float sum = 0;
            for(int i = 0; i < index; i++) {
                sum += TablicaTowarow[i].LiczbaSztuk * TablicaTowarow[i].Cena1Sztuki;
            }
            printf("Suma wartosci wszystkich towarow: %f\n", sum);
        } else if(command == 'Q' || command == 'q') {
            break;
        }
    }

    return 0;
}