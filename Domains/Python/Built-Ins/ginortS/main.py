print(*sorted(input(), key=lambda c: (-ord(c) >> 5, c in '02468', c)), sep='')
