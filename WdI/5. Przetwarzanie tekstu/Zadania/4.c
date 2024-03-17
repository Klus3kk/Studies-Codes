#include <stdio.h>
int main(void) {
  char x, ch;
  while (scanf("%c", &x) != EOF) {
    if ('A' <= x && x <= 'Z') {
      ch = x + ('a' - 'A');
      printf("%c", ch);
    }
    else
      printf("%c", x);
  }
}
