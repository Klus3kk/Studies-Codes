#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double f1(double a,double b) {
    if(a>b) {
        return 3 * a;
    } else {
        return 5 - b;
    }
}

double f2(double a,double b) {
    return pow(a,2) + pow(b,2) - 1;
}


int main() {
    double x,y;
    printf("Podaj x i y: ");
    scanf("%lf %lf",&x,&y);
    double M = f1(x,y) * f2(x,y+1);
    if (M == 0) {
        printf("Error: Dzielenie przez zero.\n");
        return 1;  
    }
    double F = (f1(x+5,y) + f2(x,y)) / M;
    printf("F(%.2lf,%.2lf) = %.2lf\n",x,y,F);
    return 0;
}