#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Student
{
    string first_name;
    string last_name;
    int day = 0;
    int month = 0;
    int year = 0;
};

int main()
{
    size_t N = 0;
    cin >> N;
    vector<Student> students(N);
    for (auto &student : students) {
        cin >> student.first_name >> student.last_name >> student.day
                >> student.month >> student.year;
    }
    size_t M = 0;
    cin >> M;
    for (size_t i = 0; i < M; ++i) {
        string request;
        size_t index = 0;
        cin >> request >> index;
        if (index > N || index == 0) {
            cout << "bad request" << endl;
        } else if (request == "name") {
            cout << students[index - 1].first_name << ' '
                 << students[index - 1].last_name << endl;
        } else if (request == "date") {
            cout << students[index - 1].day << '.' << students[index - 1].month
                 << '.' << students[index - 1].year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }
    return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
  string first_name;
  string last_name;

  int day;
  int month;
  int year;
};

int main() {
  int n;
  cin >> n;

  string first_name, last_name;
  int day, month, year;
  vector<Student> students;

  for (size_t i = 0; i < n; ++i) {
    cin >> first_name >> last_name >> day >> month >> year;

    students.push_back(Student{
      first_name,
      last_name,
      day,
      month,
      year
    });
  }

  int m;
  cin >> m;
  string query;
  int student_number;

  for (int i = 0; i < m; ++i) {
    cin >> query >> student_number;
    --student_number;

    if (query == "name" && student_number >= 0 && student_number < n) {
      cout << students[student_number].first_name << " "
           << students[student_number].last_name << endl;
    } else if (query == "date" && student_number >= 0 && student_number < n) {
      cout << students[student_number].day << "."
           << students[student_number].month << "."
           << students[student_number].year << endl;
    } else {
      cout << "bad request" << endl;
    }
  }

  return 0;
}

*/
