#include <stdio.h>
#include <stdlib.h>

char T2B(char c) {
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
    }
    return 0;
}

char B2T(char c) {
    switch (c) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
    }
    return 'A';
}

void encode(const char* input, const char* output) {
    FILE* in = fopen(input, "r");
    FILE* out = fopen(output, "wb");

    char buffer[5];
    while (fscanf(in, "%4s", buffer) == 1) {
        char byte = 0;
        for (int i = 0; i < 4; i++) {
            byte <<= 2;
            byte |= T2B(buffer[i]);
        }
        fwrite(&byte, 1, 1, out);
    }

    fclose(in);
    fclose(out);
}

void decode(const char* input, const char* output) {
    FILE* in = fopen(input, "rb");
    FILE* out = fopen(output, "w");

    char byte;
    while (fread(&byte, 1, 1, in) == 1) {
        for (int i = 3; i >= 0; i--) {
            char c = B2T((byte >> (i * 2)) & 3);
            fputc(c, out);
        }
        fputc('\n', out);
    }

    fclose(in);
    fclose(out);
}

int main() {
    char mode, input[256], output[256];

    printf("Enter mode (e for encode, d for decode): ");
    scanf(" %c", &mode);

    printf("Enter input file name: ");
    scanf("%s", input);

    printf("Enter output file name: ");
    scanf("%s", output);

    if (mode == 'e') {
        encode(input, output);
    } else if (mode == 'd') {
        decode(input, output);
    } else {
        printf("Invalid mode.\n");
    }

    return 0;
}