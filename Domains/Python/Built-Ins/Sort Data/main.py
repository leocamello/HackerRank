N, M = map(int, raw_input().split())

table = list()

for i in range(0, N):
    table.append(list(map(int, raw_input().split())))

K = int(raw_input())

table = sorted(table, key=lambda x: x[K])

for i in range(0, N):
    line = str()
    for j in range(0, M):
        line += str(table[i][j]) + " "
    print line
