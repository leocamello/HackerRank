N = int(input())

A = sorted(list(map(int, input().split())))

mindiff = abs(A[0] - A[1])

for i in range(N - 1):
    mindiff = min(mindiff, abs(A[i] - A[i + 1]))

pairs = list()
for i in range(N - 1):
    if abs(A[i] - A[i + 1]) == mindiff:
        pairs.append(A[i])
        pairs.append(A[i + 1])

print(*pairs)
