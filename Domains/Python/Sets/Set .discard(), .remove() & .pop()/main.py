n = int(raw_input())

s = set(map(int, raw_input().split()))

N = int(raw_input())

for i in range(0, N):
    args = raw_input().split()
    command = args[0]
    if command == "discard":
        s.discard(int(args[1]))
    elif command == "remove":
        s.remove(int(args[1]))
    else:
        s.pop()

print sum(s)
