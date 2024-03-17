#include <stdio.h>
#include <math.h>

int triangleValidation(double a, double b, double c) {
    if((a + b > c) && (a + c > b) && (b + c > a)) {
        return 1;
    }
    return 0;
}
int main() {
    double a,b,c;
    printf("Podaj boki trójkąta: \n");
    scanf("%lf%lf%lf", &a,&b,&c);
    if(triangleValidation(a,b,c)) {
        printf("Z tych boków można stworzyć trójkąt");
    } else {
        printf("Z tych boków nie można stworzyć trójkąta");
    }
    return 0;
}