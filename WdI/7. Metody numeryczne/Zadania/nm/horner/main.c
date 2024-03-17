#include <stdio.h>
#include <stdlib.h>

float compute_polynomial_value(float x, int n, float *a) {
     if (n == 0) 
        return *a;
     else 
        return compute_polynomial_value(x, n - 1, a) * x + *(a + n);
}

int main() {
	float x;
	int n;
	scanf("%f %d", &x, &n);
	printf("x = %f, n = %d\n", x, n);
	float *a = (float*) malloc((n + 1) * sizeof(float));
	int i;
	for(i = 0; i <= n; i++) {
	    scanf("%f", a + i);
	    
	}
	for(i = 0; i <= n; i++) {
	    printf("a[%d] = %f", i, *(a + i));
	    if (i < n)
	        printf(", ");
	    else
	        printf("\n");
	}
    printf("%g\n", compute_polynomial_value(x, n, a));
    free(a);
    return 0;
}

