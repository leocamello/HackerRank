N = int(input())

fibonacci = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377]

print (list(map(lambda x: x ** 3, fibonacci[0:N])))
