import numpy

N = int(input())

A = numpy.array([list(map(int, input().split())) for n in range(N)])
B = numpy.transpose(numpy.array([list(map(int, input().split())) for n in range(N)]))

AB = numpy.array([[numpy.dot(A[i], B[j]) for j in range(N)] for i in range(N)])

print (AB)
