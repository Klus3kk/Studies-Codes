#include <stdio.h>
#include <math.h>

int delta(int a, int b, int c) {
    return (pow(b,2) - (4 * a * c));
}



int main() {
    int a,b,c,x;
    printf("Please write a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);
    if(a < 0) {
        printf("Sorry, (a) can't be less or equal 0\n");
    } else {
        if(delta(a,b,c) < 0) {
            printf("No roots!");
        } else if (delta(a,b,c) == 0) {
            printf("One root: %f\n", (-b)/(2 * a));
        } else {
            printf("Two roots: %f, %f", ((-b)-sqrt(delta(a,b,c))) / 2 * a, ((-b)+sqrt(delta(a,b,c))) / 2 * a );
        }
    }
    return 0;
}