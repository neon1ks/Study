# Classy Critter
# Demonstrates class attributes and static methods
# Классово верная зверюшка
# Демонстрирует атибуты класса и статические методы


class Critter(object):
    """Виртуальный питомец"""
    # """A virtual pet"""
    total = 0

    @staticmethod
    def status():
        # print("\nThe total number of critters is", Critter.total)
        print("\nВсего зверюшек сейчас", Critter.total)

    def __init__(self, name):
        # print("A critter has been born!")
        print("Появилась на свет новая зверюшка!")
        self.name = name
        Critter.total += 1


# main
# print("Accessing the class attribute Critter.total:", end=" ")
print("Нахожу значение атрибута класса Critter.total:", end=" ")
print(Critter.total)

Critter.ext = 50
print(Critter.ext)

# print("\nCreating critters.")
print("\nСоздаю зверюшек.")
crit1 = Critter("зверюшка 1")
crit2 = Critter("зверюшка 2")
crit3 = Critter("зверюшка 3")

Critter.status()

# print("\nAccessing the class attribute through an object:", end=" ")
print("\nОбращаююсь к атрибуту класса через объект:", end=" ")
print(crit1.total)
print(crit1.ext)
crit1.ext = 51
print(crit1.ext)
print(Critter.ext)
# input("\n\nPress the enter key to exit.")
