#include <stdio.h>
#include <string.h>

int count_occurrences(char *s1, char *s2) {
    int count = 0;
    char *temp = s2;
    while((temp = strstr(temp, s1)) != NULL) {
        count++;
        temp++;
    }
    return count;
}

int main() {
    char s1[100], s2[100];
    printf("Podaj ciag: ");
    fgets(s1, sizeof(s1), stdin);
    printf("Podaj wzorzec: ");
    fgets(s2, sizeof(s2), stdin);

    s1[strcspn(s1, "\n")] = 0;
    s2[strcspn(s2, "\n")] = 0;
    int count = count_occurrences(s1, s2);
    printf("The pattern '%s' occurs %d times in the base string.\n", s1, count);
    return 0;
}