#include <stdio.h>
#include <string.h>


void szyfruj(char *s, int p) {
    char ch;
    for(int i = 0; i < sizeof(s); ++i) {
        ch = s[i];
        
        if (ch >= 'a' && ch <= 'z') {
            s[i] = (ch - 'a' + p) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            s[i] = (ch - 'A' + p) % 26 + 'A';
        }
    }
    printf("Zaszyfrowane: %s\n", s);
}

void odszyfruj(char *s, int p) {
    char ch;
    for(int i = 0; i < sizeof(s); ++i) {
        ch = s[i];
        
         if (ch >= 'a' && ch <= 'z') {
            s[i] = (ch - 'a' - p + 26) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            s[i] = (ch - 'A' - p + 26) % 26 + 'A';
        }
    }
    printf("Odszyfrowane: %s\n", s);
}

int main() {
    char s[150];
    int p, choose;
    printf("Podaj wiadomosc: ");
    scanf("%s", &s);

    printf("\nPodaj przesuniecie: ");
    scanf("%d", &p);
    printf("(1) Szyfruj\n(2) Odszyfruj\n");
    scanf("%d", &choose);
    switch(choose) {
        case 1:
            szyfruj(s,p);
            break;
        case 2:
            odszyfruj(s,p);
            break;
        default:
            break;
    }

    return 0;
}