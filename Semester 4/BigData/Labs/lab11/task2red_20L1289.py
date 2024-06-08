import sys
currword = None
currcount = 0
word = None
for x in sys.stdin:
    x = x.strip()
    word, count = x.split('\t', 1)
    try:
        count = int(count)
    except ValueError:
        continue
    if currword == word:
        currcount += count
    else:
        if currword:
            sys.stdout.write(currword+'\t'+str(currcount)+'\n')
        currcount = count
        currword = word
sys.stdout.write(currword+'\t'+str(currcount) + '\n')
