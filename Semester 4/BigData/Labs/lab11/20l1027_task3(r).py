# Task 3 (reducer)
import sys
curr_count = 0
curr_word = None
curr_day = None
word = None
for x in sys.stdin:
    x = x.strip()
    word, day = x.split('\t', 1)
    count = 1
    if (curr_word == word and curr_day == day):
        curr_count += count
    else:
        if curr_word:
            sys.stdout.write(curr_day+' < '+curr_word+' ' + str(curr_count)+' >\n')
        curr_count = count
        curr_day = day
        curr_word = word
sys.stdout.write(curr_day+' < '+curr_word+' ' + str(curr_count)+' >\n')