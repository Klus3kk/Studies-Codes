#include <stdio.h>
int main(void) {
    int n, x, i, sum;
    scanf("%d",&n);
    i=0;
    while(i<n){
        scanf("%d", &x);
        sum = sum + x;
        i=i+1;
    } 
    printf("%d", sum);
    return 0;
}