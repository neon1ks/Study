import pprint
import requests


class MadadipouyaForecast:

    def get(self, city):
        url = "http://weather-api.madadipouya.com/v1/weather/currentbyip?fahrenheit=false"
        data = requests.get(url).json()
        forecast = {"date": data["dt"], "temp": data["main"]["temp"]}
        return forecast


class CityInfo:

    def __init__(self, city, weather_forecast=None):
        self.city = city
        self._weather_forecast = weather_forecast or MadadipouyaForecast()

    def weather_forecast(self):
        return self._weather_forecast.get(self.city)


def _main():
    city_info = CityInfo("Irkutsk")
    forecast = city_info.weather_forecast()
    pprint.pprint(forecast)


if __name__ == "__main__":
    _main()
