from itertools import combinations

N = int(input())
letters = input().split()
K = int(input())

count, total = 0, 0

for group in combinations(letters, K):
    count += 'a' in group
    total += 1

print (count / total)
