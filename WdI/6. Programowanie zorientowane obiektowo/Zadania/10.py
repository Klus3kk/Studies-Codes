L=[1990, 1984, 1879]
index = len(L)-1
L.insert(index, 2022)
L.pop(index)
L.remove(1984)
L.sort()
L.reverse()
for i in L:
    print(i)