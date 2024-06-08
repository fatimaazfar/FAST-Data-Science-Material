# Task 3 (mapper)
import sys
for x in sys.stdin:
    x = x.strip()
    x = x.split()
    sys.stdout.write(x[0]+'\t'+x[-1]+'\n')