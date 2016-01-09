from collections import defaultdict
import sys

phone = defaultdict(str)

for _ in range(int(input())):
    name = input()
    phone[name] = input()

for line in sys.stdin:
    name = line.strip()
    if len(phone[name]) > 0:
        print(name + "=" + phone[name])
    else:
        print("Not found")
