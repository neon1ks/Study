#include <algorithm>
#include <cctype>
#include <exception>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

class Date
{
public:
    Date()
    {
        this->day = 0;
        this->month = 1;
        this->year = 1;
    }
    explicit Date(int year, int month, int day)
    {
        this->year = year;

        if (month < 1 || month > 12) {
            throw runtime_error("Month value is invalid: " + to_string(month));
        }
        this->month = month;

        if (day < 1 || day > 31) {
            throw runtime_error("Day value is invalid: " + to_string(day));
        }
        this->day = day;
    }
    int Day() const { return day; }
    int Month() const { return month; }
    int Year() const { return year; }

private:
    int day;
    int month;
    int year;
};

bool operator==(const Date &lhs, const Date &rhs)
{
    return lhs.Year() == rhs.Year() && lhs.Month() == rhs.Month()
           && lhs.Day() == rhs.Day();
}

bool operator<(const Date &lhs, const Date &rhs)
{
    if (lhs.Year() < rhs.Year()) {
        return true;
    }
    if (lhs.Year() > rhs.Year()) {
        return false;
    }
    if (lhs.Month() < rhs.Month()) {
        return true;
    }
    if (lhs.Month() > rhs.Month()) {
        return false;
    }
    if (lhs.Day() < rhs.Day()) {
        return true;
    }
    return false;
}

ostream &operator<<(ostream &stream, const Date &value)
{
    stream << setfill('0');
    stream << setw(4) << value.Year();
    stream << '-' << setw(2) << value.Month();
    stream << '-' << setw(2) << value.Day();
    return stream;
}

istream &operator>>(istream &stream, Date &value)
{
    char c = '\0';
    string origin;
    string number;

    int day = 0;
    int month = 0;
    int year = 0;

    bool error = false;
    bool digit = false;
    bool first = true;

    while (stream) {
        auto p = stream.peek();
        if (p == ' ' || p == '\t') {
            stream.get();
            continue;
        }
        break;
    }

    while (!error && stream) {
        auto p = stream.peek();
        if (p != '\n' && p != '\r' && p != ' ' && p != '\t') {
            stream.get(c);
            origin.push_back(c);
            if (first) {
                if (c == '-' || c == '+') {
                    first = false;
                    number.push_back(c);
                    continue;
                }
                if (isdigit(c) != 0) {
                    first = false;
                    digit = true;
                    number.push_back(c);
                    continue;
                }
                error = true;
                break;
            }
            if (!digit) {
                if (isdigit(c) == 0) {
                    error = true;
                    break;
                }
            }
            if (isdigit(c) != 0) {
                digit = true;
                number.push_back(c);
                continue;
            }
        }
        if (number.empty() || number == "-" || number == "+") {
            error = true;
        } else {
            year = std::stoi(number);
            number.clear();
        }
        break;
    }

    if (!error && c != '-') {
        error = true;
    }

    first = true;
    digit = false;
    while (!error && stream) {
        auto p = stream.peek();
        if (p != ' ' && p != '\t' && p != '\n' && p != '\r') {
            stream.get(c);
            origin.push_back(c);
            if (first) {
                if (c == '-' || c == '+') {
                    first = false;
                    number.push_back(c);
                    continue;
                }
                if (isdigit(c) != 0) {
                    first = false;
                    digit = true;
                    number.push_back(c);
                    continue;
                }
                error = true;
                break;
            }
            if (!digit) {
                if (isdigit(c) == 0) {
                    error = true;
                    break;
                }
            }
            if (isdigit(c) != 0) {
                digit = true;
                number.push_back(c);
                continue;
            }
        }

        if (number.empty() || number == "-" || number == "+") {
            error = true;
        } else {
            month = std::stoi(number);
            number.clear();
        }
        break;
    }

    if (!error && c != '-') {
        error = true;
    }

    first = true;
    digit = false;
    while (!error && stream) {
        auto p = stream.peek();
        if (p != ' ' && p != '\t' && p != '\n' && p != '\r') {
            stream.get(c);
            origin.push_back(c);
            if (first) {
                if (c == '-' || c == '+') {
                    first = false;
                    number.push_back(c);
                    continue;
                }
                if (isdigit(c) != 0) {
                    first = false;
                    digit = true;
                    number.push_back(c);
                    continue;
                }
                error = true;
                break;
            }
            if (!digit) {
                if (isdigit(c) == 0) {
                    error = true;
                    break;
                }
            }
            if (isdigit(c) != 0) {
                digit = true;
                number.push_back(c);
                continue;
            }
            if (isdigit(c) == 0) {
                error = true;
                break;
            }
        }

        if (number.empty() || number == "-" || number == "+") {
            error = true;
        } else {
            day = std::stoi(number);
            number.clear();
        }
        break;
    }

    if (error) {
        auto p = stream.peek();
        while (p != ' ' && p != '\t' && p != '\n' && p != '\r') {
            stream.get(c);
            origin.push_back(c);
            p = stream.peek();
        }
        throw runtime_error("Wrong date format: " + origin);
    }

    value = Date{ year, month, day };

    return stream;
}

int main()
{
    map<Date, set<string>> calendar;

    while (cin.good() && !cin.eof()) {
        try {
            string command;
            if (cin >> command) {
                if (command == "Add") {
                    Date date;
                    string event;
                    cin >> date >> event;
                    calendar[date].insert(event);
                } else if (command == "Del") {
                    Date date;
                    string event;
                    cin >> date;
                    while (cin.peek() == ' ' || cin.peek() == '\t') {
                        cin.get();
                    }
                    if (cin.peek() != '\n' && cin.peek() != '\r') {
                        cin >> event;
                    }
                    if (event.empty()) {
                        auto it_date = calendar.find(date);
                        if (it_date == calendar.end()) {
                            cout << "Deleted 0 events" << endl;
                        } else {
                            auto count = calendar[date].size();
                            calendar[date].clear();
                            calendar.erase(it_date);
                            cout << "Deleted " << count << " events" << endl;
                        }
                    } else {
                        auto it_date = calendar.find(date);
                        if (it_date != calendar.end()) {
                            auto it_event = calendar[date].find(event);
                            if (it_event != calendar[date].end()) {
                                calendar[date].erase(it_event);
                                if (calendar[date].empty()) {
                                    calendar.erase(it_date);
                                }
                                cout << "Deleted successfully" << endl;
                            } else {
                                cout << "Event not found" << endl;
                            }
                        } else {
                            cout << "Event not found" << endl;
                        }
                    }
                } else if (command == "Find") {
                    Date date;
                    cin >> date;
                    auto it_date = calendar.find(date);
                    if (it_date != calendar.end()) {
                        for (const auto &event : calendar[date]) {
                            cout << event << endl;
                        }
                    } else {
                        //cout << "Event not found" << endl;
                    }
                } else if (command == "Print") {
                    int count = 0;
                    for (const auto &[date, events] : calendar) {
                        for (const auto &event : events) {
                            cout << date << ' ' << event << endl;
                            ++count;
                        }
                    }
                    if (count == 0) {
                        //cout << "Event not found" << endl;
                    }
                } else {
                    cout << "Unknown command: " << command << endl;
                    while (cin.get() != '\n') { }
                }
            }
        } catch (const exception &e) {
            cout << e.what() << endl;
            while (cin.get() != '\n') { }
        }
    }
    return 0;
}

/*
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Date {
public:
  // конструктор выбрасывает исключение, если его аргументы некорректны
  Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if (new_month > 12 || new_month < 1) {
      throw logic_error("Month value is invalid: " + to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
      throw logic_error("Day value is invalid: " + to_string(new_day));
    }
    day = new_day;
  }

  int GetYear() const {
    return year;
  }
  int GetMonth() const {
    return month;
  }
  int GetDay() const {
    return day;
  }

private:
  int year;
  int month;
  int day;
};

// определить сравнение для дат необходимо для использования их в качестве ключей словаря
bool operator<(const Date& lhs, const Date& rhs) {
  // воспользуемся тем фактом, что векторы уже можно сравнивать на <:
  // создадим вектор из года, месяца и дня для каждой даты и сравним их
  return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
      vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

// даты будут по умолчанию выводиться в нужном формате
ostream& operator<<(ostream& stream, const Date& date) {
  stream << setw(4) << setfill('0') << date.GetYear() <<
      "-" << setw(2) << setfill('0') << date.GetMonth() <<
      "-" << setw(2) << setfill('0') << date.GetDay();
  return stream;
}

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
    storage[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event) {
    if (storage.count(date) > 0 && storage[date].count(event) > 0) {
      storage[date].erase(event);
      return true;
    }
    return false;
  }

  int DeleteDate(const Date& date) {
    if (storage.count(date) == 0) {
      return 0;
    } else {
      const int event_count = storage[date].size();
      storage.erase(date);
      return event_count;
    }
  }

  set<string> Find(const Date& date) const {
    if (storage.count(date) > 0) {
      return storage.at(date);
    } else {
      return {};
    }
  }

  void Print() const {
    for (const auto& item : storage) {
      for (const string& event : item.second) {
        cout << item.first << " " << event << endl;
      }
    }
  }

private:
  map<Date, set<string>> storage;
};

Date ParseDate(const string& date) {
  istringstream date_stream(date);
  bool ok = true;

  int year;
  ok = ok && (date_stream >> year);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int month;
  ok = ok && (date_stream >> month);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int day;
  ok = ok && (date_stream >> day);
  ok = ok && date_stream.eof();

  if (!ok) {
    throw logic_error("Wrong date format: " + date);
  }
  return Date(year, month, day);
}

int main() {
  try {
    Database db;

    string command_line;
    while (getline(cin, command_line)) {
      stringstream ss(command_line);

      string command;
      ss >> command;

      if (command == "Add") {

        string date_str, event;
        ss >> date_str >> event;
        const Date date = ParseDate(date_str);
        db.AddEvent(date, event);

      } else if (command == "Del") {

        string date_str;
        ss >> date_str;
        string event;
        if (!ss.eof()) {
          ss >> event;
        }
        const Date date = ParseDate(date_str);
        if (event.empty()) {
          const int count = db.DeleteDate(date);
          cout << "Deleted " << count << " events" << endl;
        } else {
          if (db.DeleteEvent(date, event)) {
            cout << "Deleted successfully" << endl;
          } else {
            cout << "Event not found" << endl;
          }
        }

      } else if (command == "Find") {

        string date_str;
        ss >> date_str;
        const Date date = ParseDate(date_str);
        for (const string& event : db.Find(date)) {
          cout << event << endl;
        }

      } else if (command == "Print") {

        db.Print();

      } else if (!command.empty()) {

        throw logic_error("Unknown command: " + command);

      }
    }
  } catch (const exception& e) {
    cout << e.what() << endl;
  }

  return 0;
}
*/
