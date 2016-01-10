def find_gcd(a, b):
    if a != b:
        return find_gcd(max(a, b) - min(a, b), min(a, b))
    else:
        return a

a, b = map(int, input().split())
print (find_gcd(a, b))
