m = int(raw_input())
M = list(map(int, raw_input().split()))

n = int(raw_input())
N = list(map(int, raw_input().split()))

MNDiff = set(M).difference(set(N))
NMDiff = set(N).difference(set(M))

R = list()

for e in MNDiff:
    R.append(e)

for e in NMDiff:
    R.append(e)

R.sort()

for i in R:
    print i
