string = raw_input()
substring = raw_input()

count = 0

for begin in range(len(string)):
    end = begin + len(substring)
    if string[begin:end] == substring:
        count += 1

print count
