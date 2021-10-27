#include <iostream>
#include <forward_list>
#include <sstream>

using namespace std;

template<typename T>
ostream &operator<<(ostream &out, const forward_list<T> &vi);

template<typename Collection>
string Join(const Collection &c, char d)
{
    stringstream ss;
    bool first = true;
    for (const auto &i : c) {
        if (first) {
            first = false;
        } else {
            ss << d;
        }
        ss << i;
    }
    return ss.str();
}


template<typename T>
ostream &operator<<(ostream &out, const forward_list<T> &vi)
{
    return out << '[' << Join(vi, ',') << ']';
}

void ReverseAfter(forward_list<char> &fl, char element)
{
    for (auto it_before = fl.before_begin(), it = fl.begin(); it != fl.end();
            ++it_before, ++it) {
        if (*it == element) {
            fl.erase_after(it_before);
            it = it_before;
            ++it;
            while (it != fl.end()) {
                ++it_before;
                ++it;
            }
            fl.emplace_after(it_before, element);
            break;
        }
    }
}

int main()
{
    forward_list<char> fl = { 'A', 'B', 'C', 'D', 'E', 'F' };

    ReverseAfter(fl, 'D');
    ReverseAfter(fl, 'A');
    ReverseAfter(fl, 'A');

    cout << fl << endl;

    return 0;
}
