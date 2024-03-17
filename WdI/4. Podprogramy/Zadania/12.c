// ŹLE DZIAŁAJĄCY SWAP
#include <stdio.h>
void swap1(int a, int b){
    int tmp;
    tmp= a;
    a= b;
    b= tmp;
    return;
}
int main(void){
    int X, Y;
    X= 1; Y= 2;
    printf("%d %d; ", X, Y);
    swap1(X, Y);
    printf("%d %d\n", X, Y);
}