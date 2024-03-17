digits = [0]*99
def int2digits(n, b):
    digits[0] = n % b
    i = 1
    while n > b-1:
        n //= b
        digits[i] = n % b
        i += 1
    return
def length(n, b):
    L=1
    while n > b-1:
        n //= b
        L+= 1
    return L
x = int(input())
base = int(input())
int2digits(x, base)
j = length(x, base) - 1
while j >= 0:
    print(digits[j], end="")
    j -= 1 