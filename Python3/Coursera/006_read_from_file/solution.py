import os.path


class FileReader:

    def __init__(self, path):
        self._path = path

    @property
    def path(self):
        return self._path

    def read(self):
        # try:
        #     if not os.path.exists(self._path):
        #         raise ValueError("Файл не существует", self._path)
        # except ValueError as err:
        #     message, filename = err.args[0], err.args[1]
        #     print(message, filename)
        text = str('')
        try:
            f = open(self._path)

            for line in f:
                text += line

            f.close()
        except FileNotFoundError:
            pass

        return text
