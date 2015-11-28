from itertools import combinations

N = int(input())
letters = input().split()
K = int(input())

count, total = 0, 0

for group in combinations(letters, K):
    total += 1
    has_a = False
    for c in group:
        if c == 'a':
            has_a = True
    if has_a == True:
        count += 1

print (count / total)
