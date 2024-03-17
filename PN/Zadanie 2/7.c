#include <stdio.h>

int sidesEqual(double v[]) {
    return (v[0] == v[1] && v[1] == v[2] && v[2] == v[3]);
}
int pairsEqual(double v[]) {
    return ((v[0] == v[1] && v[2] == v[3]) || (v[0] == v[2] && v[1] == v[3]) || (v[0] == v[3] && v[1] == v[2]));
}


int main() {
    double v[4];
    scanf("%lf%lf%lf%lf", &v[0], &v[1], &v[2], &v[3]);
    if(sidesEqual(v)) {
        printf("It's a square!");
    } else if (pairsEqual(v)) {
        printf("It's a rectangle!");
    } else {
        printf("It's neither a rectangle nor a square!");
    }
    return 0;
}