#include <stdio.h>
int main(void){
    int A, B, *Adr;
    A=3;
    B=4;
    Adr= &A; // *Adr == A
    B= B + *Adr;
    printf("%d %d\n", A, B);
}