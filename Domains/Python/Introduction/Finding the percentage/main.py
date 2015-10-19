N = int(raw_input())

line = raw_input().split()

name = line[0]
marks = (float(line[1]), float(line[2]), float(line[3]))

d = {name: marks}

for i in range(1, N):
    line = raw_input().split()
    name = line[0]
    marks = (float(line[1]), float(line[2]), float(line[3]))
    d[name] = marks

key = raw_input()

value = d[key]

sum = value[0] + value[1] + value[2]

print ("%.2f" % (sum / 3))
