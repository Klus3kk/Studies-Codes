#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int r = 1 + (rand() % 9), n, ns;
    printf("----Zgadnij liczbę----\nWprowadź liczbę: ");
    while(n != r) {
        scanf("%d", &n);
        if(n == ns) {
            printf("Wprowadziłeś znowu tą samą liczbę 0_0\n");
        } else if (n != r) {
            printf("Oj nie, to nie ta liczba, próbuj dalej\n");
        }
        ns = n;
    }
    printf("Brawo! Odgadłeś moją sekretną liczbę c:");
    
}