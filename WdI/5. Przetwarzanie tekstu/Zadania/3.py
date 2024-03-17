import sys
for line in sys.stdin:
    for x in line:
      if 'A' <= x and x <= 'Z':
           ch= ord(x) + ord('a') - ord('A')
           print(chr(ch), end='')
      else:
           print(x, end='')