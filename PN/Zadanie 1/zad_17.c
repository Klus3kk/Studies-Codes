#include <stdio.h>
#include <string.h>


void alphabet_maker(char a[]) {
    for(int i = 0; i < 26; i++) {
        a[i] = 97 + i;
    }
}

void letter_counter(char s[], int w[], char l[]) {
    for (int i = 0; i < strlen(s); i++) { //
        for (int j = 0; j < strlen(l); j++) {
            if(l[j] == s[i]) {
                w[j] += 1;
            }
        }
    }
}



int main() {
    char litery[26];
    char tekst[100] = "";
    int wystapienia[26] = {0};
    alphabet_maker(litery);
    printf("Wprowadz tekst: \n");
    fgets(tekst, sizeof(tekst), stdin);
    letter_counter(tekst, wystapienia, litery);
    for (int i = 0; i < 26; i++) {
        if(wystapienia[i] != 0) {
            printf("%c: %d \n",litery[i], wystapienia[i]);
        }
    }
    return 0;
}