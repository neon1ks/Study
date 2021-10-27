# Pickle It
# Demonstrates pickling and shelving data
# Законсервируем
# Демонстрирует консервацию данных и доступ к ним через интерфейс полки

import pickle, shelve

# print("Pickling lists.")
print("Консервация списков.")
variety = ["sweet", "hot", "dill"]
shape = ["whole", "spear", "chip"]
brand = ["Claussen", "Heinz", "Vlassic"]
f = open("pickles1.dat", "wb")
pickle.dump(variety, f)
pickle.dump(shape, f)
pickle.dump(brand, f)
f.close()

# print("\nUnpickling lists.")
print("\nРасконсервация списков.")
f = open("pickles1.dat", "rb")
variety = pickle.load(f)
shape = pickle.load(f)
brand = pickle.load(f)
print(variety)
print(shape)
print(brand)
f.close()

exit()

# print("\nShelving lists.")
print("\nПомещение списков на полку.")
s = shelve.open("pickles2.dat")
s["variety"] = ["sweet", "hot", "dill"]
s["shape"] = ["whole", "spear", "chip"]
s["brand"] = ["Claussen", "Heinz", "Vlassic"]
# s.sync()    # make sure data is written
s.sync()    # Убедимся, что данные записаны

# print("\nRetrieving lists from a shelved file:")
print("\nИзвлечение списков из файла полки:")
print("brand -", s["brand"])
print("shape -", s["shape"])
print("variety -", s["variety"])
s.close()

input("\n\nPress the enter key to exit.")
