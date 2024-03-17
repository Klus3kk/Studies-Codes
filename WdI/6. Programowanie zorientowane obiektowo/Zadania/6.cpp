#include <cstdio>
typedef int Bool;
#define MAX 100
class Stack {
    int Top, S[MAX];
public:
    void push(int e) {
        S[--Top] = e;
        return;
    }
    int pop() {
        return S[Top++];
    }  
    Bool empty() {
        return Top == MAX;
    }
    Stack() {
        Top = MAX;
    }
};
int main() {
    int x;
    Stack s = Stack();
    while (scanf("%d", &x) != EOF) {
        s.push(x);
    }
    while (!s.empty()) {
        printf("%d ", s.pop());
    }
    printf("\n");
}