import sys
total=0
NR= 0
for line in sys.stdin:
    NR+= 1
    x= line.split()
    NF= len(x)
    total+= NF
print("Fields: " + str(total))
print("Rows: " + str(NR))