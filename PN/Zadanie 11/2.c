#include <stdio.h>

int main() {
    char input_filename[50], output_filename[50];
    printf("Enter the input file name: ");
    scanf("%s", input_filename);
    printf("Enter the output file name: ");
    scanf("%s", output_filename);

    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    int number;
    while (fscanf(input_file, "%d", &number) == 1) {
        if (number > 137) {
            fprintf(output_file, "%d ", number);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}