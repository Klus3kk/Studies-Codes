import sys
data= []
max= 0
for line in sys.stdin:
    i, g = line.split()
    i=int(i)
    g=int(g)
    data.append({"Id": i, "Grade": g})
    if g > max:
        max=g
for item in data:
    if item["Grade"] == max:
        print(item["Id"], item["Grade"])