import math

class Vector3:
    def __init__(self, X, Y, Z):
        self.X, self.Y, self.Z = X, Y, Z

    def __sub__(self, other):
        return Vector3(self.X - other.X, self.Y - other.Y, self.Z - other.Z)

    def dot(one, other):
        return one.X * other.X + one.Y * other.Y + one.Z * other.Z

    def cross(one, other):
        X = one.Y * other.Z - one.Z * other.Y
        Y = one.Z * other.X - one.X * other.Z
        Z = one.X * other.Y - one.Y * other.X
        return Vector3(X, Y, Z)

    def norm(self):
        return math.sqrt(Vector3.dot(self, self))

    def angle(one, other):
        return math.degrees(math.acos(Vector3.dot(one, other) / (Vector3.norm(one) * Vector3.norm(other))))

i, j, k = map(float, input().split())
A = Vector3(i, j, k)

i, j, k = map(float, input().split())
B = Vector3(i, j, k)

i, j, k = map(float, input().split())
C = Vector3(i, j, k)

i, j, k = map(float, input().split())
D = Vector3(i, j, k)

AB = B - A
BC = C - B
CD = D - C

X = Vector3.cross(AB, BC)
Y = Vector3.cross(BC, CD)

print("{0:.2f}".format(Vector3.angle(X, Y)))

    
