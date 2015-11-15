import re

for i in range(int(input())):
    matches = re.findall(r"(?<= |:)((?:#)(?:[0-9A-Fa-f]{1,2}){3,4})", input())
    if matches:
        for match in matches:
            print (match)
