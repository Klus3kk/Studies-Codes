#include <stdio.h>

int main() {
    printf("  |  1  2  3  4  5 \n======================\n");
    
    for(int i = 1; i <= 5; i++) {
        printf("%d | ", i);
        for(int y = 1; y <= 5; y++) {
            printf("%2d ", i*y);
        }  
        printf("\n");
    }
    return 0;
}
