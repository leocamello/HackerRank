N = int(input())

if N % 2 != 0:
    print("Weird")
elif N > 2 and N <= 5:
    print("Not Weird")
elif N > 6 and N <= 20:
    print("Weird")
elif N > 20:
    print("Not Weird")
