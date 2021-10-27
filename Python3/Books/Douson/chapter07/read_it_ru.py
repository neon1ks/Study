# Read It
# Demonstrates reading from a text file
# Прочитаем
# Демонстрирует чтение из текстового файла

# print("Opening and closing the file.")
print("Открываю и закрываю файл.")
text_file = open("read_it.txt", "r")
text_file.close()

# print("\nReading characters from the file.")
print("\nЧитаю файл посимвольно.")
text_file = open("read_it.txt", "r")
print(text_file.read(1))
print(text_file.read(5))
text_file.close()

# print("\nReading the entire file at once.")
print("\nЧитаю файл целиком.")
text_file = open("read_it.txt", "r")
whole_thing = text_file.read()
print('"', whole_thing, '"', sep="")
text_file.close()

# print("\nReading characters from a line.")
print("\nЧитаю одну строчку посимвольно.")
text_file = open("read_it.txt", "r")
print("1)", text_file.readline(1))
print("2)", text_file.readline(5))
print("3)", text_file.readline(5))
# print("4)", next(text_file))
# text_file.read(1)
print("5)", text_file.readline(1))
print("6)", text_file.readline(5))
print("6)", text_file.readline(5))
text_file.close()

# print("\nReading one line at a time.")
print("\nЧитаю одну строчку целиком")
text_file = open("read_it.txt", "r")
print(text_file.readline())
print(text_file.readline())
print(text_file.readline())
text_file.close()

# print("\nReading the entire file into a list.")
print("\nЧитаю весь файл в список.")
text_file = open("read_it.txt", "r")
lines = text_file.readlines()
print(lines) 
print(len(lines))
for line in lines:
    print(line)
text_file.close()

# print("\nLooping through the file, line by line.")
print("\nПеребираю файл построчно.")
text_file = open("read_it.txt", "r")
for line in text_file:
    print(line)
text_file.close()

# input("\n\nPress the enter key to exit.")
