K = int(raw_input())

rooms = list(map(int, raw_input().split()))

s = set(rooms)
L = sum(rooms)
S = sum(s)

print S - ((L - S) / (K - 1))
