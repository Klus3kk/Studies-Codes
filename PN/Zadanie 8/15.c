#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256

void koduj(char* tekst) {
    for(int i = 0; i < strlen(tekst); i++) {
        if(tekst[i] >= 'a' && tekst[i] < 'z') {
            tekst[i]++;
        } else if(tekst[i] == 'z') {
            tekst[i] = 'a';
        } else if(tekst[i] > 'A' && tekst[i] <= 'Z') {
            tekst[i]--;
        } else if(tekst[i] == 'A') {
            tekst[i] = 'Z';
        }
    }
}

void dekoduj(char* tekst) {
    for(int i = 0; i < strlen(tekst); i++) {
        if(tekst[i] > 'a' && tekst[i] <= 'z') {
            tekst[i]--;
        } else if(tekst[i] == 'a') {
            tekst[i] = 'z';
        } else if(tekst[i] >= 'A' && tekst[i] < 'Z') {
            tekst[i]++;
        } else if(tekst[i] == 'Z') {
            tekst[i] = 'A';
        }
    }
}

int main() {
    char tekst[MAX_LENGTH];
    char command;
    int isTextEntered = 0; 

    while(1) {
        printf("Podaj polecenie: ");
        scanf("%c", &command); 

        switch(command) {
            case 'N':
            case 'n':
                printf("Podaj tekst: ");
                scanf("%[^\n]", tekst); // read the entire line
                isTextEntered = 1; 
                break;
            case 'K':
            case 'k':
                if(isTextEntered) {
                    koduj(tekst);
                    printf("Zakodowany tekst: %s\n", tekst);
                } else {
                    printf("Nie wprowadzono tekstu.\n");
                }
                break;
            case 'D':
            case 'd':
                if(isTextEntered) {
                    dekoduj(tekst);
                    printf("Odkodowany tekst: %s\n", tekst);
                } else {
                    printf("Nie wprowadzono tekstu.\n");
                }
                break;
            case 'Q':
            case 'q':
                return 0;
        }
    }
}