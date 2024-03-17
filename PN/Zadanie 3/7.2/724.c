#include <stdio.h>
#include <math.h>

int main() {
    int angles[] = {0, 30, 60, 90, 120};
    double tan_val, sin_val, radian, cos_val;
    printf("Kat\tSinus\t\tCosinus\t\tTangens\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < sizeof(angles) / sizeof(angles[0]); i++) {
        int angle = angles[i];
        radian = angle * M_PI / 180.0; 
        sin_val = sin(radian);
        cos_val = cos(radian);
        if(tan(radian) < 1000) {
            tan_val = tan(radian);
            printf("%d\t%.6f\t%.6f\t%.6f\n", angle, sin_val, cos_val, tan_val);
        } else {
            printf("%d\t%.6f\t%.6f\n", angle, sin_val, cos_val);
        }
    }
    return 0;
}
