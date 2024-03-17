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
      self.Top += 1
      return e
   def Empty(self):
      return self.Top == MAX
class WindowStack(Stack):
   def __init__(self):
      super().__init__()
      self.Window= 0
   def Start(self):
      self.Window= self.Top
   def LookUp(self):
      TMP= self.S[self.Window]
      self.Window += 1
      return TMP
   def Bottom(self):
      return self.Window == MAX
s= WindowStack()
for line in sys.stdin:
    for x in line.split():
        s.Push(x)
s.Start()
print(s.LookUp())
print(s.LookUp())
while not s.Empty():
    print(s.Pop()," ",end="")