from collections import namedtuple

N = int(input())
Student = namedtuple("Student", input().strip().split())

average = 0
for i in range(N):
    average += float(Student(*input().strip().split()).MARKS)

print (average / N)
