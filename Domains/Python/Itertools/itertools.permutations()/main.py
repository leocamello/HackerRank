from itertools import permutations

S, k = raw_input().split()
S= list(S)
S.sort()

for s in list(permutations(S, int(k))):
    r = str()
    for c in s:
        r += c
    print r
