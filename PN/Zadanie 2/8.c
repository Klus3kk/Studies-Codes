#include <stdio.h>
#include <math.h>

double cross_point(double a1, double a2, double b1, double b2) {
    return (b2-b1) / (a1-a2);
}


int main() {
    double a1,a2,b1,b2;
    printf("Write a1 and b1: \n");
    scanf("%lf%lf", &a1, &b1);
    printf("\nWrite a2 and b2: \n");
    scanf("%lf%lf", &a2, &b2);
    double x = cross_point(a1,a2,b1,b2);
    double y = a1 * x + b1;
    printf("The cross point: x = %lf, y = %lf\nThe distance from the start: %lf\n", 
        x, y, sqrt(pow(x,2) + pow(y,2)));
    return 0;
}