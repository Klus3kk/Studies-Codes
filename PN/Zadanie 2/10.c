#include <stdio.h>
#include <math.h>

int triangleValidation(double a, double b, double c) {
    if(a + b > c && a + c > b && b + c > a) {
        return 1;
    }
    return 0;
}

void circle() {
    double r;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &r);
    printf("Perimeter: %lf\nSurface area: %lf", 2 * M_PI * r, M_PI * pow(r,2));
}

void square() {
    double a;
    printf("Enter the side of the square: ");
    scanf("%lf", &a);
    printf("Perimeter: %lf\nSurface area: %lf", a * 4, pow(a,2));
} 

void rectangle() {
    double a,b;
    printf("Enter the two different sides of the rectangle: ");
    scanf("%lf%lf", &a, &b);
    printf("Perimeter: %lf\nSurface area: %lf", 2 * a + 2 * b, a * b);
}   

void triangle() { 
    double a,b,c,h,para;
    int choose, isPossible = 1;
    printf("What type of triangle is this?\n(1) Scalene\n(2) Isosceles\n(3) Equilateral\n\n");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        printf("Enter the sides of the triangle (a,b,c) and height (h): ");
        scanf("%lf%lf%lf%lf", &a, &b, &c, &h);
        isPossible = triangleValidation(a,b,c);
        para = a + b + c;
        break;
    case 2:
        printf("Enter the sides of the triangle (a,b) and height (h): ");
        scanf("%lf%lf%lf", &a, &b, &h);
        isPossible = triangleValidation(a,b,b);
        para = 2 * b + a;
        break;
    case 3:
        printf("Enter the side and the height (h) of the triangle: ");
        scanf("%lf", &a, &h);
        para = 3 * a;
        break;
    default:
        break;
    }
    if(choose > 0 && choose < 4 && isPossible == 1) printf("Perimeter: %lf\nSurface area: %lf", para, (1.0/2.0) * a * h);
}

void trapezoid() {
    double a,b,c,d,h,para;
    int choose;
    printf("What type of triangle is this?\n(1) Scalene\n(2) Isosceles\n\n");
    scanf("%d", &choose);
    switch (choose) {
    case 1:
        printf("Enter the bases (a,b), sides (c,d) and the height of the trapezoid: ");
        scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &d, &h);
        para = a + b + c + d;
        break;
    case 2:
        printf("Enter the bases (a,b), side (c) and the height (h) of the trapezoid: ");
        scanf("%lf%lf%lf%lf", &a, &b, &c, &h);
        para = a + b + 2 * c;
        break;
    default:
        break;
    }
    if(choose > 0 && choose < 3) printf("Perimeter: %lf\nSurface area: %lf", para,(1.0/2.0) * (a+b) * h);
}

int main() {
    int choose;
    printf("\n\n----CALCULATION OF PERIMETER AND SURFACE AREA----\n\nPlease choose the shape:\n(1) Circle\n(2) Square\n(3) Rectangle\n(4) Triangle\n(5) Trapezoid\n\n");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        circle();
        break;
    case 2:
        square();
        break;
    case 3:
        rectangle();
        break;
    case 4:
        triangle();
        break;
    case 5:
        trapezoid();
        break;
    default:
        break;
    }
    return 0;
}