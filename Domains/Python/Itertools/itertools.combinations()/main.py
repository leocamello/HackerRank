from itertools import combinations

S, k = raw_input().split()
S = list(S)
S.sort()

for i in range(1, int(k) + 1):
    for s in combinations(S, i):
        r = str()
        for c in s:
            r += c
        print r
