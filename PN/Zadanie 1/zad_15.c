#include <stdio.h>
#include <math.h>

int main() {
    double x,y;
    scanf("%lf%lf", &x, &y);
    if(x>5 && y > 3) {
        printf("T = %lf", (log(x-5) + 1)/(sqrt(y-3)));
    } else {
        printf("Brak rozwiązania");
    }
}