import re

words = re.findall(r'[0-9A-Za-z]+', input())

print(len(words))

for word in words:
    print(word)
