N = int(raw_input())

if N > 0:
    args = raw_input().split()

    T = (int(args[0]), )

    for i in range(1, N):
        T = T + (int(args[i]),)

    print hash(T)
