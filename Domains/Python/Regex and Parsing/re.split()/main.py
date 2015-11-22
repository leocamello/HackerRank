import re

for numbers in (re.split(r'[.,]+', input())):
    if len(numbers) > 0:
        print (numbers)
