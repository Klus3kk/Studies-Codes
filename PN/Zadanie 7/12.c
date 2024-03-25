#include <stdio.h>

void mergeArrays(int* array1, int size1, int* array2, int size2, int* result) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (array1[i] < array2[j])
            result[k++] = array1[i++];
        else
            result[k++] = array2[j++];
    }

    while (i < size1)
        result[k++] = array1[i++];

    while (j < size2)
        result[k++] = array2[j++];
}

int main() {
    int array1[] = {1, 3, 5, 7};
    int size1 = sizeof(array1) / sizeof(array1[0]);

    int array2[] = {2, 4, 6, 8};
    int size2 = sizeof(array2) / sizeof(array2[0]);

    int result[size1 + size2];
    mergeArrays(array1, size1, array2, size2, result);

    printf("Merged array is: ");
    for (int i = 0; i < size1 + size2; i++)
        printf("%d ", result[i]);

    return 0;
}