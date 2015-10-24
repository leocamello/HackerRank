from collections import defaultdict

n, m = map(int, raw_input().split())

l = defaultdict(int)
for i in raw_input().split():
    l[i] += 1

happiness = 0

for i in raw_input().split():
    happiness += l[i]

for i in raw_input().split():
    happiness -= l[i]

print happiness
