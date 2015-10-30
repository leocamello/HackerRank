from itertools import combinations_with_replacement

S, k = raw_input().split()
S = list(S)
S.sort()

for s in list(combinations_with_replacement(S, int(k))):
    r = str()
    for c in s:
        r += c
    print r
