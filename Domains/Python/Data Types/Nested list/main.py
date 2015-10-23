N = int(raw_input())

students = list()

for i in range(0, N):
    nameAndMark = list()
    nameAndMark.append(raw_input())
    nameAndMark.append(float(raw_input()))
    students.append(nameAndMark)

students.sort()

lowestMark = 100.1

for s in students:
    if s[1] < lowestMark:
        lowestMark = s[1]

secondLowestMark = list()
secondLowestMark.append(["", 100.1])

for s in students:
    if s[1] > lowestMark:
        if s[1] < secondLowestMark[0][1]:
            secondLowestMark = [s]
        elif s[1] == secondLowestMark[0][1]:
            secondLowestMark.append(s)

for student in secondLowestMark:
    print student[0]
