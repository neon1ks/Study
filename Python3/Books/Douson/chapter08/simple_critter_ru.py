# Simple Critter
# Demonstrates a basic class and object 
# Просто зверюшка
# Демонстрирует простейшие класс и обхект

class Critter(object):
    """Виртуальный питомец"""
#    """A virtual pet"""
    def talk(self):
#        print("Hi.  I'm an instance of class Critter.")
        print("Привет. Я зверюшка - экземпляр класса Critter.")

# main
# Основная часть
crit = Critter()
crit.talk()

# input("\n\nPress the enter key to exit.")
