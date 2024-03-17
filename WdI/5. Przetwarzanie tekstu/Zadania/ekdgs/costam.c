#include <stdio.h>
int main(){
    int c = 1, sum=0, poz=1;
    // while ((c = getchar()) != '+')
    //     if ('0' <= c && c <= '9'){
    sum += (c - '0')*poz;
        //     poz *= 10; }
        // else {printf("%d,", sum);
        //     sum= 0;
        //     poz= 1; }
    printf("%d", sum);
    return 0; }