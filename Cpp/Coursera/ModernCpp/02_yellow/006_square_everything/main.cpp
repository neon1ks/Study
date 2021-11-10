#include <iostream>
#include <map>
#include <vector>

using namespace std;

//template<typename First, typename Second>
//pair<First, Second> operator*(
//        const pair<First, Second> &l, const pair<First, Second> &r);

template<typename T>
T Sqr(const T &e);

template<typename T>
vector<T> Sqr(const vector<T> &collection);

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value> &collection);

template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second> &e);

//template<typename First, typename Second>
//pair<First, Second> operator*(
//        const pair<First, Second> &l, const pair<First, Second> &r)
//{
//    return { l.first * r.first, l.second * r.second };
//}

template<typename T>
T Sqr(const T &e)
{
    return e * e;
}

template<typename T>
vector<T> Sqr(const vector<T> &coll)
{
    vector<T> result(coll.size());
    for (size_t i = 0; i < coll.size(); ++i) {
        result[i] = Sqr(coll[i]);
    }
    return result;
}

template<typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value> &collection)
{
    map<Key, Value> result;
    for (const auto &[key, value] : collection) {
        result[key] = Sqr(value);
    }
    return result;
}

template<typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second> &e)
{
    return { Sqr(e.first), Sqr(e.second)};
}

#ifdef ONLY_HOME
int main()
{
    // Пример вызова функции
    vector<int> v = { 1, 2, 3 };
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = { { 4, { 2, 2 } },
        { 7, { 4, 3 } } };
    cout << "map of pairs:" << endl;
    for (const auto &x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second
             << endl;
    }
    return 0;
}
#endif
