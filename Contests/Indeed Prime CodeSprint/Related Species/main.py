for _ in range(int(input())):
    N = int(input())

    A = map(int, input().strip().split())
    B = map(int, input().strip().split())

    result = list()

    for pair in list(zip(A, B)):
        if len(result) == 0:
            result.append(min(pair))
        elif result[-1] <= min(pair):
            result.append(min(pair))
        else:
            result.append(max(pair))

    print ("YES" if all(result[i] <= result[i + 1] for i in range(len(result) - 1)) else "NO")
