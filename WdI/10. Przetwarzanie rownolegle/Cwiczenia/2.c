#include <stdio.h>

int S;

void PUT() {
    int x;
    x = S;
    x += 50;
    S = x;
}

void ECDL() {
    int x;
    x = S;
    x += 70;
    S = x;
}

int main(void) {
    S = 7;
    PUT();
    ECDL();
    printf("S=%d\n",S);
}