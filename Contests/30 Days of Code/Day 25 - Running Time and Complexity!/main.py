import math

for _ in range(int(input())):
    prime = True
    N = int(input())
    n = round(math.sqrt(N))
    for i in range(2, n + 1):
        if N % i == 0:
            prime = False
    if not prime or N == 1:
        print("Not prime")
    else:
        print("Prime")
