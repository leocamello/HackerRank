import re

for i in range(int(input())):
    s = input()
    while s != re.sub(r"(\s\|\|\s)", " or ", s):
        s = re.sub(r"(\s\|\|\s)", " or ", s)
    while s != re.sub(r"(\s&&\s)", " and ", s):
        s = re.sub(r"(\s&&\s)", " and ", s)
    print (s)
