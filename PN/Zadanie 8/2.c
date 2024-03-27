#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>


int main() {
    char s[100];
    int count[26] = {0};
    printf("Podaj ciag znakow: ");
    fgets(s, sizeof(s), stdin);
    int n = strlen(s);
    for(int i = 0; i < n; i++) {
        if(isalpha(s[i])) { // is it a letter?
            count[tolower(s[i]) - 'a']++; 
        }
    }
    for(int i = 0; i < 26; i++) {
        if(count[i] > 0) {
            printf("%c: %d\n", 'A'+i, count[i]);
        }
    }
    return 0;   
}