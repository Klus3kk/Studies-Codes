#include <stdio.h>
int main(void) {
  int t;
  char last;
  while ((t = getchar()) != EOF)
    last = t;
  putchar(last);
  putchar('\n');
}
// CTRL + D LINUX CTRL + Z + ENTER WINDOWS