#include <stdio.h>

int main() {
    int n;
    printf("Wprowadz n: ");
    scanf("%d", &n);
    double A[n];
    for(int i = 0; i < n; i++) {
        scanf("%lf", &A[i]);
    }
    printf("\n\n");
    for(int i = n - 1; i >= 0; i--) {
        printf("%.1lf\n", A[i]);
    }
    return 0;
}
