#include <stdio.h>

int is_symmetric(int n, int A[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] != A[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int has_empty_column(int n, int A[n][n]) {
    for(int j = 0; j < n; j++) {
        int column_sum = 0;
        for(int i = 0; i < n; i++) {
            column_sum += A[i][j];
        }
        if(column_sum == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    printf("Enter the size of the matrix (n): ");
    scanf("%d", &n);
    int A[n][n];
    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("The matrix is %ssymmetric.\n", is_symmetric(n, A) ? "" : "not ");
    printf("The matrix %shas an empty column.\n", has_empty_column(n, A) ? "" : "does not ");
    return 0;
}