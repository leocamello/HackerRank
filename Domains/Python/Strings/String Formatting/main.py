N = int(raw_input())

blen = len("{0:b}".format(N))

formats = "doXb"

for i in range(1, N + 1):
    line = ""
    for c in formats:
        line += ("{0:" + c + "}").format(i).rjust(blen) + " "
    print line
