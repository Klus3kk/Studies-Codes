#include <stdio.h>
void swap(int a[]){
    int tmp;
    tmp = a[0];
    a[0]= a[1];
    a[1]= tmp;
    return;
}
int main(void){
    int X[3];
    X[0]= 1;
    X[1]= 2;
    printf("%d %d\n", X[0],X[1]);
    swap(X);
    printf("%d %d\n", X[0],X[1]);
}