from functools import lru_cache


def fib_list(n):
    result = []
    a, b = 0, 1
    while a < n:
        result.append(a)
        a, b = b, a + b
    return result


cache_fib = {}


@lru_cache(maxsize=256)
def fib(n):
    if n <= 1:
        return n
    # if n in cache_fib:
    #     return cache_fib[n]
    # result = fib(n - 1) + fib(n - 2)
    # cache_fib[n] = result
    # return result
    return fib(n - 1) + fib(n - 2)


def main():
    import sys
    a, b = 11, 6
    if len(sys.argv) == 3:
        _, a, b = sys.argv
        if not (a.isdigit() and b.isdigit()):
            print('Values are not valid!')
            return
        a = int(a)
        b = int(b)

    print(a, b)
    print(fib_list(a))
    print(fib(b))
    print(sys.argv)


if __name__ == '__main__':
    main()
