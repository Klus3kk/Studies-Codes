#include <stdio.h>

void printMenu() {
    printf("1. Decimal to Binary\n");
    printf("2. Decimal to Octal\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Exit\n");
}

void decToBin(int n) {
    if (n > 1)
        decToBin(n / 2);
    printf("%d", n % 2);
}

void decToOct(int n) {
    if (n > 0) {
        decToOct(n / 8);
        printf("%d", n % 8);
    }
}

void decToHex(int n) {
    if (n > 0) {
        decToHex(n / 16);
        printf("%X", n % 16);
    }
}

int main() {
    int choice, n;
    while (1) {
        printMenu();
        scanf("%d", &choice);
        int result = scanf("%d", &choice);
        if(result != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("Niepoprawny wybor\n");
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &n);
                printf("Binary: ");
                decToBin(n);
                printf("\n");
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%d", &n);
                printf("Octal: ");
                decToOct(n);
                printf("\n");
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &n);
                printf("Hexadecimal: ");
                decToHex(n);
                printf("\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}