import sys

if __name__ == '__main__':
    value = int(sys.argv[1])
    for i in range(value):
        # out = " " * (value - 1 - i) + "#" * (i + 1)
        # print(out)
        print(" " * (value - 1 - i) + "#" * (i + 1), sep="")

# import sys
#
# num_steps = int(sys.argv[1])
#
# for i in range(num_steps):
#     print(" " * (num_steps - i - 1), "#" * (i + 1), sep="")
