#include <iostream>
#include <map>
#include <stdexcept>

using namespace std;

template<typename KeyType, typename ValueType>
ValueType& GetRefStrict(map<KeyType, ValueType>& input_map, KeyType key) {
    if (input_map.count(key) == 0) {
        throw runtime_error("no such key in dictionary");
    }
    return input_map[key];
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
