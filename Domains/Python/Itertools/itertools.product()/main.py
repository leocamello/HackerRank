from itertools import product

A = list(map(int, raw_input().split()))
B = list(map(int, raw_input().split()))

s = str()

for i in product(A, B):
    s += str(i) + " "

print s
