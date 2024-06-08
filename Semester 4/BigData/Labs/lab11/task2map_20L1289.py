import sys
for x in sys.stdin:
    x = x.strip()
    x = x.split()
    for i in x:
        sys.stdout.write(i+'\t1\n')