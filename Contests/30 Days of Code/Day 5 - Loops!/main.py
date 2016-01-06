T = int(input())

for _ in range(T):
    a, b, N = map(int, input().split())
    series = list()
    for i in range(N):
        series.append(a)
        for j in range(i + 1):
            series[i] += 2 ** j * b
    print(*series)
