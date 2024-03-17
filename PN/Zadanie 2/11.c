#include <stdio.h>
#include <math.h>

void potega() {
    int n, power;
    printf("Enter the number and the power: ");
    scanf("%d%d", &n, &power);
    printf("%d to the %d power is: %lf", n, power, pow(n,power));
}

void odwrotnosc() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Reciprocal of a number: %lf", 1.0/n);
}

void nlog() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("The natural logaritm of %d is: %lf", n, log(n));
}

void sinus() {
    double n;
    printf("Enter the number: ");
    scanf("%lf", &n);
    printf("Sinus: %lf", sin(n));
}

void tangens() {
    double n;
    printf("Enter the number: ");
    scanf("%lf", &n);
    printf("Tangent: %lf", tan(n));
}

int main() {
    int choose;
    printf("----CALCULATOR----\n\nPlease select an option (1-5): \n\n(1) Exponentiation\n(2) Reciprocal of a number\n(3) Natural logaritm\n(4) Sine\n(5) Tangent\n\n");
    scanf("%d", &choose);
    switch(choose) {
        case 1:
            potega();
            break;
        case 2:
            odwrotnosc();
            break;
        case 3:
            nlog();
            break;
        case 4:
            sinus();
            break;
        case 5:
            tangens();
            break;
        default:
            break;
    }
    return 0;
}