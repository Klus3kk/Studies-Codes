#include <stdio.h>
int main(void){
    struct item {int Id;
        int Grade;};
    struct item data[100];
    int max, k, i, g, j;
    max= 0;
    k= 0;
    while (scanf("%d %d", &i, &g) != EOF){
        data[k].Id= i;
        data[k].Grade= g;
        if (g > max){
            max= g; 
        }
        k+= 1;
    }
    for (j= 0; j < k; j+= 1){
        if (data[j].Grade == max)
            printf("%d %d\n", data[j].Id, data[j].Grade);
    }
}