import math

class Vector3:
    def __init__(self, X, Y, Z):
        self.X, self.Y, self.Z = X, Y, Z

    def __sub__(self, other):
        return Vector3(self.X - other.X, self.Y - other.Y, self.Z - other.Z)

    def dot(self, other):
        return self.X * other.X + self.Y * other.Y + self.Z * other.Z

    def cross(self, other):
        X = self.Y * other.Z - self.Z * other.Y
        Y = self.Z * other.X - self.X * other.Z
        Z = self.X * other.Y - self.Y * other.X
        return Vector3(X, Y, Z)

    def norm(self):
        return math.sqrt(Vector3.dot(self, self))

    def angle(one, other):
        return math.degrees(math.acos(Vector3.dot(one, other) / (Vector3.norm(one) * Vector3.norm(other))))

coords = list()
for i in range(0, 4):
    coords.append(map(float, input().split()))

A, B, C, D = Vector3(*coords[0]), Vector3(*coords[1]), Vector3(*coords[2]), Vector3(*coords[3])

X = (B - A).cross(C - B)
Y = (C - B).cross(D - C)

print("{0:.2f}".format(Vector3.angle(X, Y)))
