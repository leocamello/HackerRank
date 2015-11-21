import re

for _ in range(int(input())):
    s = input()
    print (bool(re.search(r'^[-+]?[0-9]*\.[0-9]+$', s)))
