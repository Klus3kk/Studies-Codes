#include <stdio.h>
#include <math.h>
#define MaxErr 0.03
#define ABS(A) (A<0? -(A) : (A))
float SqR(float a) {
    float X, NewX, Err;
    X = a >= 1 ? a : 1;
    NewX = 0.5 * (X + a / X);
    Err = ABS(NewX - X) / NewX;
    while (Err > MaxErr) {
        X = NewX;
        NewX = 0.5 * (X + a / X);
        Err = ABS(NewX - X) / NewX;
    }
    return NewX;
}
int main(void) {
    printf("2:%g\n", SqR(2));
    return 0;
}