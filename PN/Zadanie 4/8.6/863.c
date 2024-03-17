#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min;

    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }

    printf("\nPosortowane liczby:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int main() {
    int numbers[30];
    int n;

    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);

    if(n > 0 && n < 31) {
        for(int i = 0; i < n; i++) {
            printf("Podaj liczbe: ");
            scanf("%d", &numbers[i]);
        }
        selectionSort(numbers,n);
    } else {
        printf("\nZla liczba!");
        return 0;
    }
    return 0;
}