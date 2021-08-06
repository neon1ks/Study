#include <iostream>
#include <exception>

using namespace std;

void EnsureEqual(const string &left, const string &right)
{
    if (left != right) {
        throw runtime_error(left + " != " + right);
    }
}

int main()
{
    try {
        EnsureEqual("C++ White", "C++ White");
        EnsureEqual("C++ White", "C++ Yellow");
    } catch (runtime_error &e) {
        cout << e.what() << endl;
    }
    return 0;
}

/*
void EnsureEqual(const string& s, const string& t) {
    if (s != t) {
        throw runtime_error(s + " != " + t);
    }
}
*/
