#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

int main() {
    char text[128];
    int histogram[26] = {0};

    printf("Podaj tekst: ");
    fgets(text, sizeof(text), stdin);

    for(int i = 0; i < strlen(text); i++) {
        char c = tolower(text[i]);
        if(c >= 'a' && c <= 'z') {
            histogram[c - 'a']++;
        }
    }

    for(int i = 0; i < 26; i++) {
        if(histogram[i] > 0) {
            printf("%c: %d\n", 'a' + i, histogram[i]);
        }
    }

    return 0;
}