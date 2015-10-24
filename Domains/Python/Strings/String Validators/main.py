S = raw_input()

r = [False, False, False, False, False]

B = [(s.isalnum(), s.isalpha(), s.isdigit(), s.islower(), s.isupper()) for s in S]

for b in B:
    for i in range(0, 5):
        r[i] |= b[i]

for i in range(0, 5):
    print r[i]
