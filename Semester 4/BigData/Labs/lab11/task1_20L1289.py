import sys
for line in sys.stdin:
    for i in line:
        if (i not in ['.', '!', '-']):
            sys.stdout.write(i)