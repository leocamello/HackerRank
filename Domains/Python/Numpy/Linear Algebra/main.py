import numpy

print (numpy.linalg.det(numpy.array([list(map(float, input().split())) for n in range(int(input()))])))
