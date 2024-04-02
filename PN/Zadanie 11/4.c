#include <stdio.h>

int main() {
    FILE *file1 = fopen("P1.txt", "r");
    FILE *file2 = fopen("P2.txt", "r");
    FILE *file3 = fopen("P3.txt", "w");

    double number1, number2;
    int end1 = fscanf(file1, "%lf", &number1) != 1;
    int end2 = fscanf(file2, "%lf", &number2) != 1;

    while (!end1 && !end2) {
        if (number1 < number2) {
            fprintf(file3, "%lf ", number1);
            end1 = fscanf(file1, "%lf", &number1) != 1;
        } else {
            fprintf(file3, "%lf ", number2);
            end2 = fscanf(file2, "%lf", &number2) != 1;
        }
    }

    while (!end1) {
        fprintf(file3, "%lf ", number1);
        end1 = fscanf(file1, "%lf", &number1) != 1;
    }

    while (!end2) {
        fprintf(file3, "%lf ", number2);
        end2 = fscanf(file2, "%lf", &number2) != 1;
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}