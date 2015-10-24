from collections import defaultdict

n, m = map(int, raw_input().split())

a = defaultdict(list)
for i in range(1, n + 1):
    a[raw_input()].append(i)

for i in range(1, m + 1):
    key = raw_input()
    if len(a[key]) > 0:
        print (" ").join(str(c) for c in a[key])
    else:
        print -1
    
