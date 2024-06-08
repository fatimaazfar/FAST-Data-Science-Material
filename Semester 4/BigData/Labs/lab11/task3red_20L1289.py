import sys
currcount = 0
currword = None
currday = None
word = None
for i in sys.stdin:
    i = i.strip()
    word, day = i.split('\t', 1)
    count = 1
    if (currword == word and currday == day):
        currcount += count
    else:
        if currword:
            sys.stdout.write(currday+' < '+currword+' ' + str(currcount)+' >\n')
        currcount = count
        currday = day
        currword = word
sys.stdout.write(currday+' < '+currword+' ' + str(currcount)+' >\n')