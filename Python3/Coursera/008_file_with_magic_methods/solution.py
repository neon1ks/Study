import os.path
from pathlib import Path
import tempfile
from random import choice
from string import ascii_uppercase


class File:
    def __init__(self, path_to_file):
        self._path_to_file = path_to_file
        if not os.path.exists(path_to_file):
            Path(path_to_file).touch()
        self._f = open(path_to_file, 'r')

    def __str__(self):
        return self._path_to_file

    def __iter__(self):
        return self

    def __next__(self):
        line = self._f.readline()
        if not line:
            self._f.seek(0)
            raise StopIteration

        return line

    def read(self):
        self._f.seek(0)
        content = ""
        for line in self._f:
            content += line
        self._f.seek(0)
        return content

    def write(self, content, mode=None):
        self._f.close()
        if mode is None:
            f = open(self._path_to_file, 'w')
            result = f.write(content)
            f.close()
        else:
            f = open(self._path_to_file, 'a')
            result = f.write(content)
            f.close()

        self._f = open(self._path_to_file, 'r')
        return result

    def __add__(self, obj):
        if isinstance(obj, File):
            new_file = ''.join(choice(ascii_uppercase) for i in range(20))
            new_file_path = os.path.join(tempfile.gettempdir(), new_file)
            f = File(new_file_path)
            f.write(self.read())
            f.write(obj.read(), True)
            return f


if __name__ == '__main__':
    pass
