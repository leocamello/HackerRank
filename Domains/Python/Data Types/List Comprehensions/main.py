X = int(raw_input())
Y = int(raw_input())
Z = int(raw_input())

N = int(raw_input())

results = list()
[results.append([x, y, z]) for x in range(0, X + 1) for y in range(0, Y + 1) for z in range(0, Z + 1) if x + y + z != N]

print results
