def find_gcd(a, b):
    if a != b:
        return find_gcd(max(a, b) - min(a, b), min(a, b))
    else:
        return a

print (find_gcd(map(int, input().split())))
