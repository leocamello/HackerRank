import numpy

N, M = map(int, input().split())

elements = list()
for n in range(N):
    elements.append(input().split())

matrix = numpy.reshape(numpy.array(elements, int), (N, M))

print (numpy.transpose(matrix))
print (matrix.flatten())
