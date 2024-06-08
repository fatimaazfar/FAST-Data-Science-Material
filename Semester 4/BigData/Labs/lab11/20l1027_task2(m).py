# Task 2 (mapper)
import sys
for line in sys.stdin:
    line = line.strip()
    line = line.split()
    for i in line:
        sys.stdout.write(i+'\t1\n')