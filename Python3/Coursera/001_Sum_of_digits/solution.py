import sys

if __name__ == '__main__':
    digit_string = sys.argv[1]
    my_sum = 0
    for letter in digit_string:
        my_sum += int(letter)

    print(my_sum)

# Мы немного сжульничали и применили тут конструкции,
# с которыми вас еще не знакомили.
# Однако, это будет исправлено на второй неделе курса — обещаем :)

# import sys
# print(sum([int(x) for x in sys.argv[1]]))
