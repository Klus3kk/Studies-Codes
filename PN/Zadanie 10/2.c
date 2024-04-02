#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double oblicz(int i, int j, double A[50][50], double B[50][50]){
    double mianownik = A[i][j] + 1;
    double licznik = pow(sin(A[i][j]),2) - 3;

    if (sqrt(mianownik) <= 0) {
        return 3.31; 
    }

    B[i][j] = licznik / sqrt(mianownik);
    return B[i][j];
}


int main() {
    int n,m;
    printf("Podaj n i m: ");
    scanf("%d %d",&n,&m);
    while(n > 50 || n < 1 || m > 50 || m < 1){
        printf("Podaj n i m: ");
        scanf("%d %d",&n,&m);
    }
    double A[50][50], B[50][50];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("Podaj A[%d][%d]: ",i,j);
            scanf("%lf",&A[i][j]);
            printf("%lf\n",oblicz(i,j,A,B));
        }
    }
    return 0;
}