#include <stdio.h>
#include <string.h>

char encode(char c) {
    if ('a' <= c && c <= 'z') {
        return 'z' - (c - 'a');
    } else if ('A' <= c && c <= 'Z') {
        return c == 'Z' ? 'A' : c + 1;
    } else if (c < 128) {
        return c;
    } else {
        return ' ';
    }
}

char decode(char c) {
    if ('a' <= c && c <= 'z') {
        return 'z' - (c - 'a');
    } else if ('A' <= c && c <= 'Z') {
        return c == 'A' ? 'Z' : c - 1;
    } else if (c < 128) {
        return c;
    } else {
        return ' ';
    }
}

int main() {
    char input_filename[50], output_filename[50], mode[10];
    printf("Enter the input file name: ");
    scanf("%s", input_filename);
    printf("Enter the output file name: ");
    scanf("%s", output_filename);
    printf("Enter 'encode' or 'decode': ");
    scanf("%s", mode);

    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    char (*func)(char) = strcmp(mode, "encode") == 0 ? encode : decode;

    char c;
    while ((c = fgetc(input_file)) != EOF) {
        fputc(func(c), output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}