#include <stdio.h>

int main() {
    double T;
    int option;
    printf("Enter the temperature: \n");
    scanf("%lf", &T);
    printf("\n(1) Celsius to Fahrenheit \n(2) Fahrenheit to Celsius \n\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            printf("%lf", (9.0/5.0)*T + 32);
            break;
        case 2:
            printf("%lf", (5.0/9.0)*(T - 32));
            break;
        default:
            printf("Wrong number");
    }

    return 0;
}