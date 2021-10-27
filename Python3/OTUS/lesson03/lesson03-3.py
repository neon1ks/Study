class Vehicle:
    speed = 0
    age = 0

    def move(self):
        return f'Moving with speed {self.speed}'


class Car(Vehicle):
    def __init__(self):
        print('Vehicle speed is', self.speed)
        self.speed = 10

    def move(self):
        s = super().move()
        print('Car: Previous:', s)
        # return f'Driving car with speed {self.speed}'
        s += ' [it is a car]'
        return s


class Ship(Vehicle):

    def __init__(self):
        self.tubes = 3

    def sound(self):
        return f'Tu tu from {self.tubes} tubes'


class SportCar(Car):
    speed = 50

    def __init__(self):
        print('SportCar: Current speed is', self.speed)
        super().__init__()
        print('SportCar: And now current speed is', self.speed)
        self.speed = 70


# v = Vehicle()
# car = Car()
# ship = Ship()
s_car = SportCar()
print('\n')
# print(Car, Car.__bases__, car, car.__class__)

# print(v.move())
# print(car.move())
# print(ship.tubes)
print(s_car.move())
