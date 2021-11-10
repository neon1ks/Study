#include <iostream>
#include <string>
using namespace std;

int main()
{
    string brackets;
    getline(cin, brackets);

    bool result = true;
    unsigned opened = { 0 };
    unsigned closed = { 0 };
    for (const char c : brackets) {
        if (c == '(') {
            ++opened;
        } else {
            ++closed;
            if (closed > opened) {
                result = false;
                break;
            }
        }
    }
    if (opened != closed) {
        result = false;
    }

    cout << (result ? "YES" : "NO") << endl;

    return 0;
}
