#include <stdio.h>

void rozklad(int n) {
    int dzielnik = 2;
    
    printf("Rozkład liczby %d na czynniki pierwsze:\n", n);
    
    while (n > 1) {
        if (n % dzielnik == 0) {
            printf("%d ", dzielnik);
            n /= dzielnik;
        } else {
            dzielnik++;
        }
    }
}

int main() {
    int liczba;
    
    printf("Podaj liczbę całkowitą do rozłożenia na czynniki pierwsze: ");
    scanf("%d", &liczba);
    
    if (liczba < 2) {
        printf("Liczba musi być większa lub równa 2.\n");
        return 1;
    }
    
    rozklad(liczba);
    
    return 0;
}
