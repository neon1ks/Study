#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
    size_t M = {};
    cin >> M;
    string temp;
    getline(cin, temp);
    vector<set<char>> eyewitnesses(M);
    for (auto &e : eyewitnesses) {
        char c = {};
        cin.get(c);
        while (c != '\n') {
            e.insert(c);
            cin.get(c);
        }
    }

    size_t count_max = 0;
    size_t N = {};
    cin >> N;
    getline(cin, temp);

    vector<string> answer;
    multiset<char> number;
    //map<char, size_t> number;

    for (size_t i = 0; i < N; ++i) {
        string text = {};
        cin >> text;
        number.clear();
        for (const auto &c : text) {
            //++number[c];
            number.insert(c);
        }
        //cout << endl;
        size_t count_now = 0;
        for (const auto &e : eyewitnesses) {
            bool status = true;
            for (const auto c : e) {
                if (number.find(c) == number.end()) {
                    status = false;
                    break;
                }
            }
            if (status) {
                //cout << "DTest: true" << endl;
                ++count_now;
            }
        }

        if (count_now == count_max) {
            answer.push_back(text);
        }
        if (count_now > count_max) {
            count_max = count_now;
            answer.clear();
            answer.push_back(text);
        }
    }
    //cout << endl;
    for (const auto &a : answer) {
        cout << a << endl;
    }

    return 0;
}
