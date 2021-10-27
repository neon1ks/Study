#include <cstdint>
#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

#ifdef ONLY_HOME

enum class Lang { DE, FR, IT };

struct Region
{
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};

#endif

bool operator==(const Region &lhs, const Region &rhs)
{
    auto get_tuple = [](const Region &r) {
        return tie(r.std_name, r.parent_std_name, r.names, r.population);
    };
    return get_tuple(lhs) == get_tuple(rhs);
}

bool operator<(const Region &lhs, const Region &rhs)
{
    auto get_tuple = [](const Region &r) {
        return tie(r.std_name, r.parent_std_name, r.names, r.population);
    };
    return get_tuple(lhs) < get_tuple(rhs);
}

int FindMaxRepetitionCount(const vector<Region> &regions)
{
    int result = 0;

    map<Region, int> region_map;
    for (const auto &r : regions) {
        auto now = ++region_map[r];
        if (now > result) {
            result = now;
        }
    }

    return result;
}

#ifdef ONLY_HOME

int main()
{
    cout << FindMaxRepetitionCount({
            { "Moscow", "Russia",
                    { { Lang::DE, "Moskau" }, { Lang::FR, "Moscou" },
                            { Lang::IT, "Mosca" } },
                    89 },
            { "Russia", "Eurasia",
                    { { Lang::DE, "Russland" }, { Lang::FR, "Russie" },
                            { Lang::IT, "Russia" } },
                    89 },
            { "Moscow", "Russia",
                    { { Lang::DE, "Moskau" }, { Lang::FR, "Moscou" },
                            { Lang::IT, "Mosca" } },
                    89 },
            { "Moscow", "Russia",
                    { { Lang::DE, "Moskau" }, { Lang::FR, "Moscou" },
                            { Lang::IT, "Mosca" } },
                    89 },
            { "Russia", "Eurasia",
                    { { Lang::DE, "Russland" }, { Lang::FR, "Russie" },
                            { Lang::IT, "Russia" } },
                    89 },
    }) << endl;

    cout << FindMaxRepetitionCount({
            { "Moscow", "Russia",
                    { { Lang::DE, "Moskau" }, { Lang::FR, "Moscou" },
                            { Lang::IT, "Mosca" } },
                    89 },
            { "Russia", "Eurasia",
                    { { Lang::DE, "Russland" }, { Lang::FR, "Russie" },
                            { Lang::IT, "Russia" } },
                    89 },
            { "Moscow", "Russia",
                    { { Lang::DE, "Moskau" }, { Lang::FR, "Moscou deux" },
                            { Lang::IT, "Mosca" } },
                    89 },
            { "Moscow", "Toulouse",
                    { { Lang::DE, "Moskau" }, { Lang::FR, "Moscou" },
                            { Lang::IT, "Mosca" } },
                    89 },
            { "Moscow", "Russia",
                    { { Lang::DE, "Moskau" }, { Lang::FR, "Moscou" },
                            { Lang::IT, "Mosca" } },
                    31 },
    }) << endl;

    return 0;
}

#endif
