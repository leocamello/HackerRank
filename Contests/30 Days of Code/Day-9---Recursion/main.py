def find_gcd(a,b):
   #Write base condition
    if a == b:
        return a
    else:
        return find_gcd(max(a, b) - min(a, b), min(a, b)) 
#Take input
a, b = map(int, input().split())
gcd=find_gcd(a,b)
print (gcd)
