import re

for _ in range(int(input())):
    UID = input()
    isvalid = "Invalid"
    if len(UID) == 10:
        count = 0
        matches = re.findall(r'(?:([0-9A-Za-z])(?!.*\1))', UID)
        for match in matches:
            count += 1
        if count == 10:
            if re.search(r'(.*[0-9]+.*[0-9]+.*[0-9]+.*)', UID) != None:
                if re.search(r'(.*[A-Za-z]+.*[A-Za-z]+.*)', UID) != None:
                    isvalid = "Valid"
    print (isvalid)
