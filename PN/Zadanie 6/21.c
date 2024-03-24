#include <stdio.h>

void napisz_dane(int n, char A[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}

void draw(int n, char A[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i <= j) {
                A[i][j] = "X";
            } else if(i > j) {
                A[i][j] = " ";
            }
        }
    }
    table_print(n, A);
}


void table_print(int n, char A[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Podaj wielkosc matrycy (n): ");
    scanf("%d", &n);
    char A[n][n];
    draw(n, A);
    return 0;
}