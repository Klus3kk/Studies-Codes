#include <stdio.h>
#include <math.h>

int main() {
    float x1 = 1.0,x2 = 5.0,y1 = 1.0, y2 = 10.0,Z,kx = 1.0, ky = 1.0;
    for(float x = x1; x <= x2; x += kx) {
        for (float y = y1; y <= y2; y += ky) {
            Z = sqrt(log(x-y) + 1) * ((x/y) - 1);
            if(isnan(Z)) {
                printf("Nie istnieje\n");
            } else {
                printf("%lf,%lf : %lf\n", x,y,Z);
            }
        }
    }
    return 0;
}