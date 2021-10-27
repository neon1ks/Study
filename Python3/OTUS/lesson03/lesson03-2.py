class MyClass1:
    pass


class MyClass2(object):
    pass


print(MyClass1, type(MyClass1), MyClass1.__bases__)
print(MyClass2, type(MyClass2), MyClass2.__bases__)

m = MyClass1()
m.attr = '123'
print(m is m)


n = MyClass1()
print(n is m)

l1 = [1, 2, 3]
l2 = [1, 2, 3]

print(l1 == l2)
print(l1 is l2)

# print(m, type(m), m.__class__)


class Human:
    pass


h = Human()
h.name = 'John'
h.age = 42


def print_human(human):
    print(Human)
    # print(human)
    print(human.name, human.age)


print_human(h)


class Point(object):

    attr = 42

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def add(self, point):
        if not isinstance(point, Point):
            raise TypeError('Please provide Point isinstance')
        return Point(self.x + point.x, self.y + point.y)

    # def __add__(self, other):
    #     return self.add(other)

    __add__ = add

    def __iadd__(self, other):
        if not isinstance(other, Point):
            raise TypeError('Please provide Point isinstance')
        self.x += other.x
        self.y += other.y
        return self

    def __str__(self):
        return f'<Point {self.x}, {self.y}>'


p = Point(2, 3)
p2 = Point(1, 1)

p3 = p + p2
print(p.x, p.y)
print(p.add(p2))
p3 += Point(1, 3)
print(p3)
