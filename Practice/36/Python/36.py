import math
import copy


class Point:
    def __init__(self, a1=0, a2=0, coord_system="Cartesian"):
        if type(a1) == str:
            zap = a1.find(",")
            self.x = float((a1[1:zap]))
            self.y = float((a1[zap + 1 : -2]))
        elif coord_system == "Polar":
            self.x = math.cos(a2) * a1
            self.y = math.sin(a2) * a2

        else:
            self.x = a1
            self.y = a2

    def __eq__(self, another):
        return (abs(self.x - another.x) < 10 ** -10) and (
            abs(self.y - another.y) < 10 ** -10
        )

    def __ne__(self, another):
        return not self == another

    def __repr__(self):
        return f"Point({self.x},{self.y})"

    def __str__(self):
        return f"({self.x},{self.y})"

    def get_x(self):
        return self.x

    def get_y(self):
        return self.y

    def get_r(self):
        return math.hypot(self.x, self.y)

    def get_phi(self):
        return math.atan2(self.y, self.x)

    def set_x(self, x):
        self.x = x

    def set_y(self, y):
        self.y = y

    def set_r(self, r):
        phi = self.get_phi()
        self.x = math.cos(phi) * r
        self.y = math.sin(phi) * r

    def set_phi(self, phi):
        r = self.get_r()
        self.x = math.cos(phi) * r
        self.y = math.sin(phi) * r


with open("data.txt") as fin:
    original = [Point(p) for p in fin.readline().split(", ")]

simulacrum = copy.deepcopy(original)
for p in simulacrum:
    print(p, end="")
    p.set_x(p.get_x() + 10)
    p.set_phi(p.get_phi() + 180 * math.pi / 180)
    p.set_y(-p.get_y())
    p.set_x(-p.get_x() - 10)
    print(p)

print("\nIt works!\n" if simulacrum == original else "\nIt not works!\n")