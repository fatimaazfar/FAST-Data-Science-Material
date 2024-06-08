# Task 2 (reducer)
import sys
curr_word = None
curr_count = 0
word = None
for line in sys.stdin:
    line = line.strip()
    word, count = line.split('\t', 1)
    try:
        count = int(count)
    except ValueError:
        continue
    if curr_word == word:
        curr_count += count
    else:
        if curr_word:
            sys.stdout.write(curr_word+'\t'+str(curr_count)+'\n')
        curr_count = count
        curr_word = word
sys.stdout.write(curr_word+'\t'+str(curr_count) + '\n')
