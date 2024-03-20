#include <stdio.h>

int main() {
    int W = 4, K = 5, x, y;
    double t[W][K];
    for(int i = 0; i < W; i++) {
        for(int j = 0; j < K; j++) {
            printf("Wprowadz liczbe do tabeli do indeksu %d x %d: ", i, j);
            scanf("%lf", &t[i][j]);
        }
        printf("\n");
    }
    printf("Wprowadz x i y: ");
    scanf("%d%d", &x, &y);
    while(x <= 0 || x > W) {
        printf("Wprowadz x: ");
        scanf("%d", &x);
    }
    while(y <= 0 || y > K) {
        printf("Wprowadz y: ");
        scanf("%d", &y);
    }
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            printf("%lf ", t[i][j]);
        }
        printf("\n");
    }
    return 0;
}
