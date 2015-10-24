from collections import defaultdict

n = int(raw_input())

words = list()
word_counter = defaultdict(int)

for i in range(0, n):
    key = raw_input().strip()
    word_counter[key] += 1
    words.append(key)

print len(word_counter)

res = list()
for word in words:
    count = word_counter[word]
    if count > 0:
        res.append(count)
        word_counter[word] = 0

print (" ").join(str(c) for c in res)
