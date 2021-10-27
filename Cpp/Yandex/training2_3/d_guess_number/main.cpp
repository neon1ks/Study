#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>

using namespace std;

string read_numbers(istream &stream, vector<int> &numbers)
{
    string line;
    getline(stream, line);
    line.erase(line.find_last_not_of(" \n\r\t") + 1);
    if (line == "HELP") {
        //cout << "DTest: Help" << endl;
        return line;
    }
    numbers.clear();
    istringstream line_stream(line);
    while (!line_stream.eof()) {
        int number = {};
        line_stream >> number;
        numbers.push_back(number);
    }
    //cout << "DTest: 1" << endl;
    getline(stream, line);
    //cout << "DTest: 2" << endl;
    line.erase(line.find_last_not_of(" \n\r\t") + 1);
    return line;
}

int main()
{
    int maximum = {};
    cin >> maximum;

    set<int> answer = {};

    for (int i = 1; i <= maximum; ++i) {
        answer.insert(i);
    }
    vector<int> numbers = {};
    string word;
    getline(cin, word);
    word = read_numbers(cin, numbers);
    //int index = 1;
    //cout << "DTest: index = " << index << endl;
    while (word != "HELP") {
        if (word == "YES") {
            set<int> new_answer = {};
            for (auto &n : numbers) {
                if (answer.find(n) != answer.end()) {
                    new_answer.insert(n);
                }
            }
            answer = new_answer;
        }
        if (word == "NO") {
            for (auto &n : numbers) {
                auto it = answer.find(n);
                if (it != answer.end()) {
                    answer.erase(it);
                }
            }
        }
        word = read_numbers(cin, numbers);
    }

    bool first = true;
    for (auto n : answer) {
        if (first) {
            first = false;
        } else {
            cout << ' ';
        }
        cout << n;
    }
    cout << endl;
    return 0;
}
