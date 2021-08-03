#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<string> strings;

    size_t count = 0;
    cin >> count;
    for (size_t i = 0; i < count; ++i) {
        static string temp;
        cin >> temp;
        strings.insert(temp);
    }
    cout << strings.size() << endl;
    return 0;
}

/*
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> strings;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        strings.insert(s);
    }
    cout << strings.size() << endl;

    return 0;
}
*/
