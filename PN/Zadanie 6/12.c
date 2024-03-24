#include <stdio.h>

void potega(int n, int a) {
    if (a == 0) 
        printf("%d\n", 1);
    else {
        int wynik = n;
        for (int i = 1; i < a; i++) {
            int suma = 0;
            for (int j = 0; j < n; j++) {
                suma += wynik;
            }
            wynik = suma;
        }
        printf("%d\n", wynik);
    }
}

int main() {
    int a,n;
    printf("Podaj liczbe (n) i jej potege (a): ");
    scanf("%d%d", &n, &a);
    potega(n,a);
    return 0;
}