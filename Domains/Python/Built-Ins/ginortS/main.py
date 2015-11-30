def comparer(c):
    if c.islower():
        return ord(c) - 123
    elif c.isupper():
        return ord(c) - 65
    elif c.isdigit():
        if (int(c) % 2) != 0:
            return ord(c)
        else:
            return ord(c) + 10


print (*sorted(input(), key=comparer), sep="")
