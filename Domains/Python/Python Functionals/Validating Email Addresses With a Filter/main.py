import re

N = int(input())

emails = list()
for i in range(0, N):
    emails.append(input())

regex = r'^[\w\d-]+@[A-Za-z0-9]+\.\w?\w?\w$'

print (sorted(list(filter(lambda email : re.search(regex, email), emails))))
