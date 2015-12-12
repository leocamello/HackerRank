def action1(i, j):
    counter[scenes[actors[i]]] -= 1
    scenes[actors[i]] -= 1
    counter[scenes[actors[i]]] += 1
    counter[scenes[j]] -= 1
    scenes[j] += 1
    counter[scenes[j]] += 1
    actors[i] = j

def action2(p):
    print(sum(counter[i] for i in range(p)))

from collections import defaultdict

M, N, Q = map(int, input().split())

actors = list(map(int, input().split()))

scenes = [0] * M
for i in range(N):
    scenes[actors[i]] += 1

counter = defaultdict(int)
for i in range(M):
    counter[scenes[i]] += 1

for _ in range(Q):
    A, *args = list(map(int, input().split()))

    if A == 1:
        action1(args[0], args[1])
    if A == 2:
        action2(args[0])
