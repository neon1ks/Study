class MyIterable:
    def __init__(self, start, stop):
        if not stop > start:
            raise ValueError('Start has to be < than stop')
        self.start = start
        self.stop = stop
        # self.current = start
        self.reset()

    def __iter__(self):
        return self

    def __next__(self):
        if self.current < self.stop:
            result = self.current
            self.current += 1
            return result
        raise StopIteration

    def reset(self):
        self.current = self.start


it = MyIterable(stop=3, start=1)
for i in it:
    print(i, end=' ')

print()
print(iter(it))

it.reset()
iterable = iter(it)
print(next(iterable))
iterable.reset()
print(next(iterable))

# print(next(it))
# print(next(it))
# print(next(it))
