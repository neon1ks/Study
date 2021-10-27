class Base:

    val = 42

    def do_one_thing(self):
        '''Returns one thing'''
        raise NotImplementedError

    def do_another_thing(self, *args, **kwargs):
        '''does something'''
        raise NotImplementedError


class AnotherType(type):
    pass


class MyClass(Base, metaclass=AnotherType):
    '''
    A simple class
    '''

    def do_one_thing(self):
        return '1 thing'

    def do_another_thing(self, *args, **kwargs):
        return f'{args} | {kwargs}'


m = MyClass()

print(m.__dict__)
print()
print(m.__dir__())

print(m.do_another_thing(1, 2, 3, abc='qwe'))
print(m.do_one_thing())

print(type(MyClass))
print(repr(type))

AnotherClass = type('AnotherClass', (MyClass,), {'val': 13})
print(AnotherClass)
print(vars(AnotherClass))
print(isinstance(AnotherClass, MyClass))

ac = AnotherClass()
print(isinstance(ac, MyClass))

print(MyClass.__doc__)
