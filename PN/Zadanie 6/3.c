#include <stdio.h>

int nwd(int a, int b) {
    int z;
    while(b != 0) {
        z = b;
        b = a % b;
        a = z;
    }
    return a;
}



int main() {
    int a,b;
    printf("Podaj a i b: ");
    scanf("%d%d", &a,&b);
    printf("%d",nwd(a,b));
    return 0;
}