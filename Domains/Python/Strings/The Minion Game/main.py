S = raw_input()
Stuart, Kevin = 0, 0
vowels = set(S).intersection(set("AEIOU"))

for i in range(0, len(S)):
    if S[i] in vowels:
        Kevin += len(S) - i
    else:
        Stuart += len(S) - i

if Kevin > Stuart:
    print "Kevin " + str(Kevin)
elif Stuart > Kevin:
    print "Stuart " + str(Stuart)
else:
    print "Draw"
