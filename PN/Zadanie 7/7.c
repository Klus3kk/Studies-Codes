#include <stdio.h>

void reversePrint() {
    char c = getchar();
    if (c != '\n') {
        reversePrint();
        putchar(c);
    }
}

int main() {
    printf("Enter a string: ");
    reversePrint();
    return 0;
}