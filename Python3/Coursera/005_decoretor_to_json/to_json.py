import functools
import json


def value_to_json(value):
    # print("value_to_json")
    if type(value) is str:
        return '"' + value + '"'
    elif type(value) is True:
        return "true"
    elif type(value) is False:
        return "false"
    elif type(value) is None:
        return "null"
    elif type(value) is dict:
        return dict_to_json(value)
    elif type(value) is list or type(value) is set:
        return list_to_json(value)
    elif type(value) is tuple:
        return tuple_to_json(value)
    else:
        return str(value)


def dict_to_json(values: dict) -> str:
    # print("dict_to_json")
    result = "{"
    first = False

    for key, value in values.items():
        if first:
            result += ', '

        first = True
        result += '"' + key + '": '
        result += value_to_json(value)

    result += "}"

    return result


def list_to_json(values: list) -> str:
    print("list_to_json")
    result = "["
    first = False

    for value in values:
        if first:
            result += ', '

        first = True

        result += value_to_json(value)

    result += "]"

    return result


def tuple_to_json(values: tuple) -> str:
    return '"' + value_to_json(values[0]) + '": ' + value_to_json(values[1])


def to_json(func):
    @functools.wraps(func)
    def wrapped(*args, **kwargs):
        data = func(*args, **kwargs)
        return json.dumps(data)
    return wrapped


if __name__ == '__main__':
    @to_json
    def get_data():
        return 43, 45

    print(get_data())
