#include <stdio.h>
int main(void) {
int c;
while ((c = getchar()) != EOF)
    if ('A' <= c && c <= 'Z')
    putchar(c + 'a' - 'A');
    else putchar(c);
return 0;
}