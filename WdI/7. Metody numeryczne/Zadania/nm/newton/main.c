#include <stdio.h>
#include <math.h>
#define MAX_ERR 0.03

float compute_sqaure_root(float a) {
	float x = a >= 1 ? a : 1.0;
	float new_x = 0.5 * (x + a / x);
	float err= fabs(new_x - x) / new_x;
	while (err > MAX_ERR) {
		x = new_x;
		new_x = 0.5 * (x + a / x);
		err = fabs(new_x - x) / new_x;
	}
	return new_x;
}

int main() {
	float a;
	scanf("%f", &a);
    printf("%f:%g\n", a, compute_sqaure_root(a));
    return 0;
}

