#include <stdio.h>

void calculate_ratio(int n, int A[n][n], char choice, int index1, int index2) {
    int sum1 = 0, sum2 = 0;

    if(choice == 'r' || choice == 'R') {
        for(int j = 0; j < n; j++) {
            sum1 += A[index1][j];
            sum2 += A[index2][j];
        }
    } else if(choice == 'c' || choice == 'C') {
        for(int i = 0; i < n; i++) {
            sum1 += A[i][index1];
            sum2 += A[i][index2];
        }
    }

    if(sum2 != 0) {
        float ratio = (float)sum1 / sum2;
        printf("\nRatio: %.2f", ratio);
    } else {
        printf("\nCannot calculate ratio. Sum of second row/column is 0.");
    }
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
    char choice;
    int index1, index2;
    printf("Enter 'r' to calculate the ratio for rows or 'c' for columns: ");
    scanf(" %c", &choice);
    printf("Enter the indices of the two rows/columns (0-based): ");
    scanf("%d%d", &index1, &index2);
    calculate_ratio(n, A, choice, index1, index2);
    return 0;
}