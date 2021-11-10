#include <iostream>
#include <map>
#include <stdexcept>

using namespace std;

template<typename Key, typename Value>
Value &GetRefStrict(map<Key, Value> &m, const Key &v);

template<typename Key, typename Value>
Value &GetRefStrict(map<Key, Value> &m, const Key &v)
{
    if (m.find(v) == m.end()) {
        throw runtime_error("There is not key");
    }
    return m.at(v);
}

#ifdef ONLY_HOME
int main()
{
    try {
        map<int, string> m = {{0, "value"}};
        string& item = GetRefStrict(m, 0);
        item = "newvalue";
        cout << m[0] << endl; // выведет newvalue
    } catch (const exception &e) {
        cout << "Message: " << e.what() << '\n';
        cout << "Type:    " << typeid(e).name() << endl;
    }

    return 0;
}
#endif
