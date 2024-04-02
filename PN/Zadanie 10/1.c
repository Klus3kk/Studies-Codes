#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double oblicz(int i, int j, double a, double b){
    double mianownik = (b * i) - j + a;
    double licznik = (a * i) - (b * j);

    if (licznik < 0) {
        return 0.0; 
    }

    if (log(mianownik) <= 0) {
        return 1.03; 
    }

    return sqrt(licznik) / log(mianownik);
}


int main() {
    int n,m;
    double S = 0.0,a = 1.0,b = 1.0;
    printf("Podaj n i m: ");
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            S += oblicz(i,j,a,b);
        }
    }
    printf("Wynik: %lf\n",S);
    return 0;
}