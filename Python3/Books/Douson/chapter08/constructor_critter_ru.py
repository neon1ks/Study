# Constructor Critter
# Demonstrates constructors
# Зверушка с конструктором
# Демонстрирует метод-конструктор


class Critter(object):
    """Виртуальный питомец"""
#    """A virtual pet""" 
    def __init__(self):
        # print("A new critter has been born!")
        print("Появилась на свет новая зверюшка!")

    def talk(self):
        # print("\nHi.  I'm an instance of class Critter.")
        print("\nПривет. Я зверюшка - экземпляр класса Critter.")

# main
crit1 = Critter()
crit2 = Critter()

crit1.talk()
crit2.talk()

# input("\n\nPress the enter key to exit.")
