array = ([list(map(int, input().split())) for _ in range(6)])

largestSum = -100

for i in range(4):
    for j in range(4):
        sum = array[i][j]
        sum += array[i][j + 1]
        sum += array[i][j + 2]
        sum += array[i + 1][j + 1]
        sum += array[i + 2][j + 0]
        sum += array[i + 2][j + 1]
        sum += array[i + 2][j + 2]
        largestSum = max(largestSum, sum)

print(largestSum)
