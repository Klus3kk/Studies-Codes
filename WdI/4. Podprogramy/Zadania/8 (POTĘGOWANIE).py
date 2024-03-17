# ITERACJA
def fact(n):
    prod= 1
    j= 2
    while j <= n:
        prod *= j
        j += 1
    return prod
print(fact(4)) 

# REKURENCJA
def fact(n):
 if n==0:
    return 1   
 else:
    return n*fact(n-1)
print(fact(4)) 