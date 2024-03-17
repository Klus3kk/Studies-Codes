#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    int n,m;
    printf("Podaj ilosc liczb (n) oraz maksymalny przedzial losowania (0-m): ");
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        printf("%d\n", rand() % m);
    }
    return 0;
}