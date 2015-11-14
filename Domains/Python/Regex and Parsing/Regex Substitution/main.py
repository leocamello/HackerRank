import re

for i in range(int(input())):
    print (re.sub(r"(?<= )\|\|(?= )", "or", re.sub(r"(?<= )&&(?= )", "and", input())))
