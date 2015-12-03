import re
import email.utils

for _ in range(int(input())):
    pair = email.utils.parseaddr(input())
    if re.search(r'^[\w\d\.-]+@[A-Za-z]+\.\w?\w?\w$', pair[1]) != None:
        print (email.utils.formataddr((pair[0], pair[1])))
