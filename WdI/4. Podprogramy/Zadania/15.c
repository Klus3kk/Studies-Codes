#include <stdio.h>
int Sigma(int From, int To, int (*F)(int n)){
    int j, Sum;
    Sum= 0;
    j= From;
    while (j<=To){
        Sum+= F(j);
        j+= 1; }
    return Sum;
}
int fact(int n){
    if (n==0)
        return 1;
    return n*fact(n-1);
}
int main(void){
    printf("%d\n", Sigma(1, 4, fact));
} 