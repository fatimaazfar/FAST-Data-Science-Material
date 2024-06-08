import sys
for i in sys.stdin:
    i = i.strip()
    i = i.split()
    sys.stdout.write(i[0]+'\t'+i[-1]+'\n')