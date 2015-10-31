from collections import Counter

S = list(raw_input())
C = Counter(S)

most_common = C.most_common()

most_common = sorted(most_common, key=lambda pair: pair[0])
most_common = sorted(most_common, key=lambda pair: pair[1], reverse=True)

for i in range(0, 3):
    r = most_common[i]
    print str(r[0]) + " " + str(r[1])
