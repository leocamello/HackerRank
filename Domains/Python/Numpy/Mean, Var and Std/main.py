import numpy

N, M = map(int, input().split())

A = numpy.array([list(map(int, input().split())) for n in range(N)])

print (numpy.mean(A, axis = 1))
print (numpy.var(A, axis = 0))
print (numpy.std(A))
