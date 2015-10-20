L = list()

N = int(raw_input())

for i in range(0, N):
    args = raw_input().split()
    command = args[0]
    if command == "insert":
        L.insert(int(args[1]), int(args[2]))
    elif command == "append":
        L.append(int(args[1]))
    elif command == "count":
        L.count(int(args[1]))
    elif command == "index":
        L.index(int(args[1]))
    elif command == "remove":
        L.remove(int(args[1]))
    elif command == "pop":
        L.pop()
    elif command == "reverse":
        L.reverse()
    elif command == "sort":
        L.sort()
    else:
        print L
