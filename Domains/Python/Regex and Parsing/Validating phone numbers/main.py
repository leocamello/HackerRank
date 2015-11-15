import re

for i in range(int(input())):
    match = re.search(r"\b[789]{1}\d{9}\b", input())
    if match:
        print ("YES")
    else:
        print ("NO")
