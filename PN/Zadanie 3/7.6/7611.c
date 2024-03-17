#include <stdio.h>
#include <stdlib.h>

void replaceWithSquares(int number) {
    int squares[10]; // Tablica na kwadraty cyfr
    int result = 0;
    int position = 1;

    // Wypełnij tablicę kwadratami cyfr
    for (int i = 0; i < 10; i++) {
        squares[i] = i * i;
    }

    // Zastąp cyfry ich kwadratami i dodaj do wyniku
    while (number > 0) {
        int digit = number % 10;
        result += squares[digit] * position;
        position *= 10;
        number /= 10;
    }

    printf("Wynik: %d\n", result);
}

int main() {
    char numberStr[100]; // Tablica na wczytaną liczbę jako łańcuch znaków

    // Wczytaj liczbę jako łańcuch znaków
    printf("Podaj liczbę: ");
    scanf("%s", numberStr);

    // Przekonwertuj łańcuch na liczbę całkowitą
    int number = atoi(numberStr);

    // Wywołaj funkcję replaceWithSquares
    replaceWithSquares(number);

    return 0;
}
