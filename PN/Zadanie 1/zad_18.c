#include <stdio.h>
#include <math.h>

int equation(int n) {
    if(n == 1) {
        return (pow(n,2) + 1); 
    } 
    return (pow(n-1,2) + 1) * equation(n-1);
}



int main() {
    int n;
    scanf("%d", &n);
    while(n <= 1) {
        printf("Podaj liczbę większą od 1\n");
        scanf("%d", &n);
    }
    printf("%d",equation(n));
}