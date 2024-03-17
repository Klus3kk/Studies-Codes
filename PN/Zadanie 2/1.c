#include <stdio.h>

void biggest(double x, double y, double z) {
    if(x < y) {
        if(y > z) {
            printf("%lf", y);
        } else if (z > x) {
            printf("%lf", z);
        } else {
            printf("%lf", x);
        }
    } else {
        if (x > z) {
            printf("%lf", x);
        } else if (z > y) {
            printf("%lf", z);
        } else {
            printf("%lf", y);
        }
    }
}

int main() {
    double x,y,z;
    scanf("%lf%lf%lf", &x, &y, &z);
    biggest(x,y,z);
    return 0;
}