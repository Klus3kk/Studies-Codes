#include <stdio.h>

int main() {
    char hex1[10], hex2[10];
    int num1, num2, result;
    char operator;

    printf("Enter two hexadecimal numbers and an operator (+, -, *): ");
    scanf("%s %c %s", hex1, &operator, hex2);

    sscanf(hex1, "%x", &num1); // i could just use the letters D,O,M (dodawanie, odejmowanie, mnozenie) but i've discovered this interesting function
    sscanf(hex2, "%x", &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        default:
            printf("Invalid operator\n");
            return 1;
    }

    printf("Result: %x\n", result);

    return 0;
}