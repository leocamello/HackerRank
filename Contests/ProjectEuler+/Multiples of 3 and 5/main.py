def sumOfMultiplesOfKBellowN(K, N):
    count = (N - 1) // K
    sumOfCount = ((count + 1) * count) // 2
    return sumOfCount * K

for _ in range(int(input())):
    N, sum = int(input()), 0

    sum += sumOfMultiplesOfKBellowN(3, N)
    sum += sumOfMultiplesOfKBellowN(5, N)
    sum -= sumOfMultiplesOfKBellowN(3 * 5, N)

    print (sum)
