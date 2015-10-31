from collections import Counter

X = int(raw_input())

shoes = list(map(int, raw_input().split()))

C = Counter(shoes)

N = int(raw_input())

earned = 0

for i in range(0, N):
    size, price = map(int, raw_input().split())
    if C[size] > 0:
        earned += price
        C[size] -= 1

print earned
