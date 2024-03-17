import sys
for line in sys.stdin:
    x= line.split()
    if x[3] == "I1":
       print(x[1], x[0])