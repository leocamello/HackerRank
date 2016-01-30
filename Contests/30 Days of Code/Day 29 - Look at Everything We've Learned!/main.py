T = int(input())

for _ in range(T):
    s = input()
    length = len(s)
    isFunny = True
    for i in range(1, length):
        S = abs(ord(s[i]) - ord(s[i - 1]))
        R = abs(ord(s[length - i - 1]) - ord(s[length - i]))
        if S != R:
            isFunny = False
            break
    if isFunny:
        print("Funny")
    else:
        print("Not Funny")
