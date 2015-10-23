S = raw_input()
s = raw_input()

i = 0
count = 0
while i < len(S) - len(s):
    j = S[i:].find(s)
    if j > 0:
        count += 1
        i += j + 1
    else:
        pass

print count
