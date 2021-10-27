# from fib import fib
# from rects import rects
# import fib
# import rects


# print(fib.fib_list(11))
# print(fib.fib(6))
# print('Rect 3 4', rects.perim(3, 4))

# try:
#     # 1 / 0
#     print('Zero')
#     # '42' + 10
#     print('Type')
#     # [1, 2][2]
#     print('Index')
# except (ZeroDivisionError, TypeError, IndexError) as e:
#     print(type(e), e)
#     print('Error div 0 or TypeError')
#
#
# try:
#     1 / 0
#     print('Zero')
#     # '42' + 10
#     print('Type')
#     # [1, 2][2]
#     print('Index')
# except ZeroDivisionError:
#     print('Error div 0')
# except TypeError:
#     print('TypeError')
# except IndexError:
#     print('IndexError')
# print('I\'m working!')

import logging

logging.basicConfig(
    format='%(filename)s[LINE:%(lineno)d]# \
    %(levelname)-8s [%(asctime)s]  %(message)s',
    level=logging.DEBUG)

# debug
# info
# warning
# error
# critical


def fails():
    logging.info('Entered fails')
    1 / 0


try:
    fails()
    # 1 / 0
    # print('Zero')
    # '42' + 10
    # print('Type')
    # [1, 2][2]
    # print('Index')
    exc = Exception()
    print(exc)
    raise exc
except Exception as e:
    # print('Got Exception', type(e), e.args, type(e.args))
    # logging.error('Got Exception %s, %s', type(e), e.args, exc_info=e)
    logging.exception('Got Exception %s, %s', type(e), e.args)

# print('I\'m working!')

logging.debug('working!')
