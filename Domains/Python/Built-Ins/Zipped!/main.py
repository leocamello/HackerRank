N, X = map(int, raw_input().split())

subjects = list()

for i in range(0, X):
    subjects.append(list(map(float, raw_input().split())))

students = zip(*subjects)

for i in range(0, N):
    marks = 0.0
    for j in range(0, X):
        marks += students[i][j]
    print marks / X
    
