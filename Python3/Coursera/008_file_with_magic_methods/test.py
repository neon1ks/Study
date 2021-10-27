import os.path
from solution import File

path_to_file = 'some_filename.txt'
print(os.path.exists(path_to_file))
print() # False

file_obj = File(path_to_file)
print(os.path.exists(path_to_file))
print() # False

print(file_obj)
print()

print(file_obj.read())
print()

print(file_obj.write('some text'))
print()

print(file_obj.read())
print()

print(file_obj.write('other text'))
print()

print(file_obj.read())
print()

file_obj_1 = File(path_to_file + '_1')
file_obj_2 = File(path_to_file + '_2')
print(file_obj_1.write('line 1\n'))
print()
print(file_obj_2.write('line 2\n'))
print()

new_file_obj = file_obj_1 + file_obj_2
print(isinstance(new_file_obj, File))
print() # True

print(new_file_obj)
print()
print(new_file_obj.read())

print("test:")
for line in new_file_obj:
    print(ascii(line))

print()

new_path_to_file = str(new_file_obj)
print(os.path.exists(new_path_to_file)) # True
print() 
 
file_obj_3 = File(new_path_to_file)
print(file_obj_3)
print()  # C:\Users\Media\AppData\Local\Temp\71b9e7b695f64d85a7488f07f2bc051c
