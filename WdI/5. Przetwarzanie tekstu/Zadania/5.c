#include <stdio.h>
int main(void) {
int c, Num = 0;
while ((c = getchar()) != EOF)
    if (c == 'a') Num++;
printf("%d\n", Num);
return 0;
}