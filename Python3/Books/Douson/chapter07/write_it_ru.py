# Write It
# Demonstrates writing to a text file
# Запишем
# Демонстрирует запись в текстовый файл

# print("Creating a text file with the write() method.")
print("Создаю текстовый файл методом write().")
text_file = open("write_it_1.txt", "w")
text_file.write("Line 1\n")
text_file.write("This is line 2\n")
text_file.write("That makes this line 3\n")
text_file.close()

# print("\nReading the newly created file.")
print("\nЧитаю вновь созданный файл.")
text_file = open("write_it_1.txt", "r")
print(text_file.read())
text_file.close()

# print("\nCreating a text file with the writelines() method.")
print("\nСоздаю текстовый файл методом writelines().")
text_file = open("write_it_2.txt", "w")
lines = ["Line 1\n",
         "This is line 2\n",
         "That makes this line 3\n"]
text_file.writelines(lines)
text_file.close()

# print("\nReading the newly created file.")
print("\nЧитаю вновь созданный файл.")
text_file = open("write_it_2.txt", "r")
print(text_file.read())
text_file.close()

# input("\n\nPress the enter key to exit.")
