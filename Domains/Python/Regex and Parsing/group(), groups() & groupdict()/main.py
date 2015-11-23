import re

m = re.search(r'(?!_)(\d|\w)\1', input())
if m is not None:
    print (m.group(0)[0])
else:
    print (-1)
