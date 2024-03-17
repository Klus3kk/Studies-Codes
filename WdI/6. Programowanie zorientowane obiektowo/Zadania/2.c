#include <stdio.h>
typedef int Bool;
#define MAX 100
int Top = MAX, Stack[MAX];
void push(int e) {
    Stack[--Top] = e;
    return;
}
int pop() {
    return Stack[Top++];
}
Bool empty() {
    return Top == MAX;
}
int main(void) {
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }
    for (i--; i >= 0; i--) {
        printf("%d", pop());
    }
    printf("\n");
    printf("Empty:%d", empty());
    printf("\n");
    return 0;
}