
class MyDict:

    def __init__(self):
        self.storage = {}

    def __setitem__(self, key, value):
        self.storage[key] = value
    
    def __getitem__(self, key):
        return self.storage[key]


def _main():
    my_dict = MyDict()  
    my_dict['a'] = 'b'
    print(my_dict['a'])  # b
    print(my_dict['q'])  # KeyError


if __name__ == "__main__":
    _main()
