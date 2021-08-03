#include <iostream>
#include <string>

using namespace std;

struct Specialization
{
    string value;
    explicit Specialization(string new_value) : value(move(new_value)){};
};

struct Course
{
    string value;
    explicit Course(string new_value) : value(move(new_value)){};
};

struct Week
{
    string value;
    explicit Week(string new_value) : value(move(new_value)){};
};

struct LectureTitle
{
    string specialization;
    string course;
    string week;

    LectureTitle(
            Specialization new_specialization, Course new_course, Week new_week)
    {
        specialization = new_specialization.value;
        course = new_course.value;
        week = new_week.value;
    }
};

int main()
{
    LectureTitle title(
            Specialization("C++"), Course("White belt"), Week("4th"));
    return 0;
}

/*
#include <iostream>
#include <string>

using namespace std;

struct Specialization {
  explicit Specialization(const string& new_value) {
    value = new_value;
  }
  string value;
};

struct Course {
  explicit Course(const string& new_value) {
    value = new_value;
  }
  string value;
};

struct Week {
  explicit Week(const string& new_value) {
    value = new_value;
  }
  string value;
};

struct LectureTitle {
  LectureTitle(const Specialization& new_specialization,
               const Course& new_course,
               const Week& new_week) {
    specialization = new_specialization.value;
    course = new_course.value;
    week = new_week.value;
  }
  string specialization;
  string course;
  string week;
};
*/
