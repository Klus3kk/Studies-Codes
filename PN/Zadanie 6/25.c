#include <stdio.h>
#include <string.h>

char find_most_frequent_char(char *str) {
    int count[256] = {0};
    int len = strlen(str);
    int max = 0;
    char result;

    for(int i = 0; i < len; i++) {
        count[(int)str[i]]++;
        if(max < count[(int)str[i]]) {
            max = count[(int)str[i]];
            result = str[i];
        }
    }
    return result;
}

int main() {
    char str[100];
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    char most_frequent = find_most_frequent_char(str);
    printf("The most frequent character is '%c'.\n", most_frequent);
    return 0;
}