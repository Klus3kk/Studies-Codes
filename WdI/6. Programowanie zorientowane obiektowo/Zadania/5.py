import sys
MAX= 100
class Stack:
    def __init__(self):
        self.S= [0]*MAX
        self.Top= MAX
    def Push(self, e):
        self.Top-= 1
        self.S[self.Top]= e
    def Pop(self):
        e= self.S[self.Top]
        self.Top+= 1
        return e
    def Empty(self):
        return self.Top == MAX
s= Stack()
for line in sys.stdin:
    for x in line.split():
        s.Push(x)
while not s.Empty():
    print(s.Pop()," ",end="")