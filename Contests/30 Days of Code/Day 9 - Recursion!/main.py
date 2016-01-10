def find_gcd(a, b):
    if b != 0:
        return find_gcd(b, a % b)
    else:
        return a

a, b = map(int, input().split())
print (find_gcd(a, b))
