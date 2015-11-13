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

    def mod(self):
        return "{0:.2f}{1:+.2f}i".format(abs(self.complex), 0)

C = map(float, input().split())
D = map(float, input().split())

X = MyComplex(complex(*C))
Y = MyComplex(complex(*D))

print (X + Y)
print (X - Y)
print (X * Y)
print (X / Y)
print (X.mod())
print (Y.mod())
