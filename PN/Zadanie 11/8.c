#include <stdio.h>

double srednia(double a, double b, double c, double d) {
    return (a + b + c + d) / 4;
}

double max(double a, double b, double c, double d) {
    double max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    return max;
}

double min(double a, double b, double c, double d) {
    double min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    return min;
}

int main() {
    double (*wsk[3])(double, double, double, double) = {srednia, max, min};

    FILE *input = fopen("Pomiary.txt", "r");
    FILE *output = fopen("Wyniki.txt", "w");

    int serie, kod;
    double a, b, c, d;
    while (fscanf(input, "%d%lf%lf%lf%lf%d", &serie, &a, &b, &c, &d, &kod) == 6) {
        double wynik = wsk[kod](a, b, c, d);
        fprintf(output, "%d %lf %d\n", serie, wynik, kod);
    }

    fclose(input);
    fclose(output);

    return 0;
}