class MyComplex:
    def __init__(self, complex):
        self.complex = complex

    def __add__(self, other):
        c = self.complex + other.complex
        return "{0:.2f}{1:+.2f}i".format(c.real, c.imag + 0)

    def __sub__(self, other):
        c = self.complex - other.complex
        return "{0:.2f}{1:+.2f}i".format(c.real, c.imag + 0)

    def __mul__(self, other):
        c = self.complex * other.complex
        return "{0:.2f}{1:+.2f}i".format(c.real, c.imag + 0)

    def __truediv__(self, other):
        c = self.complex / other.complex
        return "{0:.2f}{1:+.2f}i".format(c.real, c.imag + 0)

def mod(myComplex):
    return "{0:.2f}{1:+.2f}i".format(abs(myComplex.complex), 0)

A, B = map(float, input().split())
C, D = map(float, input().split())

E = MyComplex(complex(A, B))
F = MyComplex(complex(C, D))

print (E + F)
print (E - F)
print (E * F)
print (E / F)
print (mod(E))
print (mod(F))
