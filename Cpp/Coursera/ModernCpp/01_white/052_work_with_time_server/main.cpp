#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer()
{
    static int index = 0;
    ++index;

    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */
    if (index == 1) {
        return "01:02:03";
    }
    if (index == 2) {
        throw system_error(error_code());
    }
    if (index == 3) {
        throw invalid_argument("Invalid argument");
    }

    return "02:03:04";
}

class TimeServer
{
public:
    string GetCurrentTime()
    {
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
        try {
            last_fetched_time = AskTimeServer();
        } catch (const system_error &e) {
            ;
        } catch (...) {
            throw;
        }
        return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

int main()
{
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    for (int i = 0; i < 4; ++i) {
        try {
            cout << ts.GetCurrentTime() << endl;
        } catch (exception &e) {
            cout << "Exception got: " << e.what() << endl;
        }
    }
    return 0;
}

/*
#include <exception>
#include <system_error>

using namespace std;

class TimeServer {
public:
  string GetCurrentTime() {
    // поместим вызов функции AskTimeServer в try-catch блок
    try {
      last_fetched_time = AskTimeServer();
    } catch (const system_error&) {  // ловим только system_error
    }
    // возвращаем значение поля — либо обновлённое, либо нет
    return last_fetched_time;
  }

private:
  string last_fetched_time = "00:00:00";
};
*/
