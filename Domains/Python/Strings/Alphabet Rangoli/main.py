N = int(input())

line_width = N * 4 - 3

for i in range(N - 1):
    top = ("-").join(chr(ord('a') + N - j - 1) for j in range(i + 1))
    print ((top + top[::-1][1:]).center(line_width, '-'))

center = ("-").join(chr(ord('a') + N - j - 1) for j in range(N))
print ((center + center[::-1][1:]).center(line_width, '-'))

for i in range(N - 1):
    bottom = ("-").join(chr(ord('a') + N - j - 1) for j in range(N - i - 1))
    print ((bottom + bottom[::-1][1:]).center(line_width, '-'))
