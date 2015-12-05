import re

N, M = map(int, input().split())

columns = list()

for m in range(M):
    columns.append(list())

for n in range(N):
    row = input()
    for m in range(M):
        columns[m].append(row[m])

decoded = str()
for column in columns:
    decoded += ('').join(column)

print (re.sub(r'(?<=([0-9A-Za-z]))\W+(?=([0-9A-Za-z]))', " ", decoded))
