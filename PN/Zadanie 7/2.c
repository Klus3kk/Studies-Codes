#include <stdio.h>
#include <stdlib.h>
#include <time.h>

union Bag {
    int i;
    char c;
    float f;
};

int main() {
    srand(time(NULL));
    int n;
    printf("Podaj n: ");
    scanf("%d", &n);
    union Bag array[n];
    for(int i = 0; i < n; i++) {
        int choice = rand() % 3;
        switch(choice) {
            case 0:
                array[i].i = rand() % 100;
                printf("int: %d\n", array[i].i);
                break;
            case 1:
                array[i].c = rand() % 26 + 'a';
                printf("char: %c\n", array[i].c);
                break;
            case 2:
                array[i].f = (float)rand() / RAND_MAX;
                printf("float: %f\n", array[i].f);
                break;
        }
    }
    return 0;
}