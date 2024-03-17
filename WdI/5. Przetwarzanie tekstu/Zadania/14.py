import sys
import re
for line in sys.stdin:
    if re.search("ne", line):
       print(line, end='')