#include <stdio.h>

void calculate_R(int A[15][15], int B[15][15], int n, int m, int R[15][15]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            R[i][j] = A[i][j] == B[i][j] ? 1 : 0;
        }
    }
}

void calculate_P(int A[15][15], int B[15][15], int n, int m, int P[15][15]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            P[i][j] = A[i][j] > B[i][j] ? 1 : 0;
        }
    }
}

int main() {
    int n, m;
    printf("Podaj n i m: ");
    scanf("%d %d", &n, &m);
    while(n > 15 && n <= 0|| m > 15 && m <= 0) {
        printf("Podaj n i m: ");
        scanf("%d %d", &n, &m);
    }
    int A[15][15], B[15][15];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("Podaj element A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("Podaj element B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    int R[15][15], P[15][15];
    calculate_R(A, B, n, m, R);
    calculate_P(A, B, n, m, P);

    printf("\nR = \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    printf("\nP = \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", P[i][j]);
        }
        printf("\n");
    }

    return 0;
}