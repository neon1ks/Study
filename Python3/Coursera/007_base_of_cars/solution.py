import csv
import os.path


class CarBase:
    def __init__(self, brand, photo_file_name, carrying):
        if brand == "":
            raise ValueError("Невалидные данные", brand)

        if photo_file_name == "":
            raise ValueError("Невалидные данные", photo_file_name)

        file_ext = os.path.splitext(photo_file_name)
        print(file_ext)
        if file_ext[0] == "" or (file_ext[1] != '.jpg' and file_ext[1] != '.jpeg' and file_ext[1] != '.png' and file_ext[1] != '.gif'):
            raise ValueError("Невалидные данные", photo_file_name)

        self.brand = brand
        self.photo_file_name = photo_file_name
        self.carrying = 0.0
        try:
            self.carrying = float(carrying)
        except (ValueError, OverflowError):
            raise ValueError("Невалидные данные", carrying)

    def get_photo_file_ext(self):
        file_ext = os.path.splitext(self.photo_file_name)[-1]
        return file_ext


class Car(CarBase):
    def __init__(self, brand, photo_file_name, carrying, passenger_seats_count):
        super().__init__(brand, photo_file_name, carrying)
        self.passenger_seats_count = 0
        try:
            self.passenger_seats_count = int(passenger_seats_count)
        except (ValueError, OverflowError):
            raise ValueError("Невалидные данные", passenger_seats_count)

        self.car_type = 'car'

    def get_photo_file_ext(self):
        result = super().get_photo_file_ext()
        return result


class Truck(CarBase):
    def __init__(self, brand, photo_file_name, carrying, body_whl):
        super().__init__(brand, photo_file_name, carrying)
        self.body_whl = body_whl
        self.car_type = 'truck'
        params = body_whl.split('x')
        self.body_width = 0.0
        self.body_height = 0.0
        self.body_length = 0.0
        if len(params) == 3:
            try:
                self.body_length = float(params[0])
                self.body_width = float(params[1])
                self.body_height = float(params[2])
            except (ValueError, OverflowError):
                self.body_width = 0.0
                self.body_height = 0.0
                self.body_length = 0.0

    def get_photo_file_ext(self):
        result = super().get_photo_file_ext()
        return result

    def get_body_volume(self):
        return self.body_width * self.body_height * self.body_length


class SpecMachine(CarBase):
    def __init__(self, brand, photo_file_name, carrying, extra):
        super().__init__(brand, photo_file_name, carrying)
        self.extra = extra
        self.car_type = 'spec_machine'
        self.extra = extra

        if extra == "":
            raise ValueError("Невалидные данные", extra)

    def get_photo_file_ext(self):
        return super(SpecMachine, self).get_photo_file_ext()


def get_car_list(csv_filename):
    car_list = []
    with open(csv_filename) as csv_fd:
        reader = csv.reader(csv_fd, delimiter=';')
        next(reader)  # пропускаем заголовок
        for row in reader:
            if len(row) == 0:
                break
            try:
                if row[0] == 'car':
                    car_list.append(Car(row[1], row[3], row[5], row[2]))
                elif row[0] == 'truck':
                    car_list.append(Truck(row[1], row[3], row[5], row[4]))
                elif row[0] == 'spec_machine':
                    car_list.append(SpecMachine(row[1], row[3], row[5], row[6]))
            except ValueError:
                pass

    return car_list


def _main():
    pass


if __name__ == "__main__":
    _main()
