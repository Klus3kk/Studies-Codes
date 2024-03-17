#include <stdio.h>
#include <math.h>

int wspolliniowosc(int xa,int ya,int xb,int yb,int xc,int yc) {
    if(((xb-xa)*(yc-ya))==((yb-ya)*(xc-xa))) {
        return 1;
    }
    return 0;
}


int main() {
    int xa, ya, xb, yb, xc, yc;
    printf("Podaj parametry punktu A (x,y): ");
    scanf("%d%d", &xa, &ya);
    printf("\nPodaj parametry punktu B (x,y): ");
    scanf("%d%d", &xb, &yb);
    printf("\nPodaj parametry punktu C (x,y): ");
    scanf("%d%d", &xc, &yc);
    if(wspolliniowosc(xa,ya,xb,yb,xc,yc)) {
        printf("\nPunkty sa wspolliniowe");
    } else {
        printf("\nPunkty nie sa wspolliniowe");
    }
    return 0;
}