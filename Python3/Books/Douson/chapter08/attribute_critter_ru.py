# Attribute Critter
# Demonstrates creating and accessing object attributes
# Зверюшка с атрибутами
# Демонстрирует создание атрибутов объекта и доступ к ним

class Critter(object):
    """Виртуальный питомец"""
#    """A virtual pet"""
    def __init__(self, name):
#        print("A new critter has been born!")
        print("Появилась на свет новая зверюшка!")
        self.name = name

    def __str__(self):
#        rep = "Critter object\n"
#        rep += "name: " + self.name + "\n"
        rep = "Объект класса Critter\n"
        rep += "имя: " + self.name + "\n"
        return rep  

    def talk(self):
#        print("Hi.  I'm", self.name, "\n")
        print("Привет. Меня зовут", self.name, "\n")

# main
crit1 = Critter("Бобик")
crit1.talk()

crit2 = Critter("Мурзик")
crit2.talk()

print("Вывод объекта crit1 на экран:")
print(crit1)

print("Непосредственный доступ к атрибуту crit1.name:")
print(crit1.name)
crit1.years = 10
print("years =", crit1.years)

# input("\n\nPress the enter key to exit.")
