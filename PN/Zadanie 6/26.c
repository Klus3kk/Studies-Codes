#include <stdio.h>
#include <string.h>

void find_longest_substring(char *str, char c) {
    int max_length = 0, length = 0;
    int start = 0, max_start = 0;

    for(int i = 0; str[i]; i++) {
        if(str[i] == c) {
            length++;
            if(length > max_length) {
                max_length = length;
                max_start = start;
            }
        } else {
            length = 0;
            start = i + 1;
        }
    }

    if(max_length > 0) {
        printf("The longest substring of '%c' starts at index %d and has length %d.\n", c, max_start, max_length);
    } else {
        printf("The character '%c' does not occur in the string.\n", c);
    }
}

int main() {
    char str[100], c;
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter the character: ");
    scanf(" %c", &c);
    str[strcspn(str, "\n")] = 0;
    find_longest_substring(str, c);
    return 0;
}