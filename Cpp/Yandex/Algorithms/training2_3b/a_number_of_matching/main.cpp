#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

void get_numbers(const string &line, set<int> &numbers)
{
    istringstream line_stream(line);
    while (!line_stream.eof()) {
        int number = {};
        line_stream >> number;
        numbers.insert(number);
    }
}

int main()
{
    string line;
    getline(cin, line);
    set<int> numbers1 = {};
    get_numbers(line, numbers1);

    getline(cin, line);
    set<int> numbers2 = {};
    get_numbers(line, numbers2);

    int count = { 0 };
    for (auto number : numbers1) {
        if (numbers2.find(number) != numbers2.end()) {
            ++count;
        }
    }

    cout << count << endl;

    return 0;
}
