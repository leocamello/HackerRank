N = int(raw_input())

A = list(map(int, raw_input().split()))

largestNumber = -101

for a in A:
    if a > largestNumber:
        largestNumber = a

secondLargestNumber = -101

for a in A:
    if a > secondLargestNumber and a < largestNumber:
        secondLargestNumber = a

print secondLargestNumber
