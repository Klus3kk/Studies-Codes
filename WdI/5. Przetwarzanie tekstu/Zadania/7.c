#include <stdio.h>
int main(void) {
char txt[100];
int Num = 0;
while (scanf("%s", &txt) != EOF)
    Num++;
printf("%d\n", Num);
return 0;
}