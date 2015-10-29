A = set(map(int, raw_input().split()))

res = True
for i in range(0, int(raw_input())):
    B = set(map(int, raw_input().split()))
    if len(B.intersection(A)) != len(B) or len(B.difference(A)) != 0:
        res = False

print res
