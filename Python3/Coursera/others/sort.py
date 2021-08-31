import random

numbers = []
for _ in range(10):
	numbers.append(random.randint(1, 20))

print(sorted(numbers))
print(numbers)
print("")
numbers.sort()
print(numbers)
print("")
print("")
print(sorted(numbers, reverse=True))
print("")
numbers.sort(reverse=True)
print(numbers)

