#include <stdio.h>
#include <stdlib.h>

double find_max(double *arr, int n) {
    double max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

double find_min(double *arr, int n) {
    double min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

double find_average(double *arr, int n) {
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

int main() {
    int n;
    printf("Podaj n: ");
    scanf("%d", &n);

    double *T = malloc(n * sizeof(double));
    for(int i = 0; i < n; i++) {
        printf("Podaj T[%d]: ", i);
        scanf("%lf", &T[i]);
    }

    double (*funcs[3])(double*, int) = {find_max, find_min, find_average}; // interesting

    while(1) {
        int command;
        printf("Podaj polecenie: ");
        scanf("%d", &command);
        if(command >= 0 && command <= 2) {
            printf("%lf\n", funcs[command](T, n));
        } else {
            break;
        }
    }

    free(T);
    return 0;
}