class Base:

    val = 42

    def do_one_thing(self):
        '''Returns one thing'''
        raise NotImplementedError

    def do_another_thing(self, *args, **kwargs):
        '''does something'''
        raise NotImplementedError


def function(self):
    return 42


a_list = []


class Meta(type):

    def __new__(cls, name, bases, attrs_dict):
        print('Class:', cls)
        print('Name:', name)
        print('Bases', bases)
        print('Attributes', attrs_dict)
        # return super().__new__(cls, name, bases, attrs_dict)
        x = super().__new__(cls, name, bases, attrs_dict)
        x.function = function
        # print(x)
        a_list.append(x)
        return x

    def function(self):
        return 42


def fun(self, value=1, param=None):
    if param is None:
        param = []
    param.append(value)
    # print(self)
    print(value)
    print(param)
    return param


class MyClass(object, metaclass=Meta):
    pass


m = MyClass()
print(dir(m))


class MyClass2(Base, metaclass=Meta):

    attr = 'Attribute'
    val = 42
    another = fun


m2 = MyClass2()
# print()
# print(dir(m2))
# print(m2.function())
# print(m2.another())

# print(a_list[0] is MyClass)

res = m2.another(1)
print(res)
res2 = m2.another(2, res)
print(res, res2, res is res2)
print(m2.another(3))
