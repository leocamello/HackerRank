N, L = int(input()), input().split()
print (all([(int(x) > 0) for x in L]) and any([(x == x[::-1]) for x in L]))
