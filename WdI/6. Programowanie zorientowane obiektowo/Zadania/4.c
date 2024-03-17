#include <stdio.h>
#include <stdlib.h>
typedef struct Elem Item;
struct Elem { int Val;
            Item* Next;
            };
Item* First;
#define ElemS sizeof(Item)
void push(int e) {
    Item* p;
    p = malloc(ElemS);
    p->Val = e;
    (*p).Next = First;
    First = p;
    return;
}
int pop() {
    Item* p; int e;
    p = First;
    First = (*p).Next;
    e = (*p).Val;
    free(p);
    return e;
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
    return 0;
}