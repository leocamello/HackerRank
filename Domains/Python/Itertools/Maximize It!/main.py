from itertools import product

K, M = map(int, raw_input().split())

L = list()

for i in range(0, K):
    l = list(map(int, raw_input().split()))
    l.pop(0)

    L.append(l)

max = 0
for i in (list(product(*L))):
    s = 0
    for j in i:
        s += pow(j, 2)
    r = s % M
    if r > max:
        max = r

print max
