Top= 99
Stack= [0]*100
def push(e):
    global Top
    Top -= 1
    Stack[Top] = e
    return
def pop():
    global Top
    e= Stack[Top]
    Top += 1
    return e
x= int(input())
y= int(input())
push(x)
push(y)
print(pop())
print(pop()) 