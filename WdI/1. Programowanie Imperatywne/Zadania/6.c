#include <stdio.h>
int digi(int a, int b) {
    int r, p, zer, jed, sys;
    r = a; // liczba
    sys = b; // system
    p = 1;
    zer = 0; // liczba zer
    jed = 0; // liczba jedynek
    while(a >= p) {
        if(r % sys == 1) {
            jed += 1;
        } else if (r % sys == 0) {
            zer += 1;
        }
        p = p * sys;
        r /= sys;
    }
    printf("%s%d%s%d%s", "Liczba zer: ", zer, "\nLiczba jedynek: ", jed, "\n");
    return 0;
}
int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", digi(x,y));
    return 0;
}