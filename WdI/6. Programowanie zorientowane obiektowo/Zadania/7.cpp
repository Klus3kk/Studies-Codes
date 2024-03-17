#include <cstdio>
typedef int Bool;
#define MAX 100
class Stack {
protected:
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
class WindowStack : public Stack {
protected:
   int Window;
public:
   void Start() {
      Window = Top;
      return;
   }
   int LookUp() {
      return S[Window++];
   }
   Bool Bottom() {
      return Window == MAX;
   }
   WindowStack() {
      return;
   }
};
int main()
{
   int x;
   WindowStack s = WindowStack();
   while (scanf("%d", &x) != EOF)
      s.push(x);
   s.Start();
   printf("%d ", s.LookUp());
   printf("%d\n", s.LookUp());
   while (!s.empty())
      printf("%d ", s.pop());
   printf("\n");
}