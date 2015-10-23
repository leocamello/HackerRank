S = raw_input()

args = raw_input().split()

i = int(args[0])
c = args[1]

l = list(S)

l[i] = c

print "".join(l)
