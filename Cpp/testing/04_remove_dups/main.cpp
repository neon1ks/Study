#include <cctype>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

void RemoveDups(char *pStr)
{
    if (pStr == nullptr) {
        return;
    }
    size_t index = 0;
    size_t index_insert = 0;
    set<char> cache;
    while (pStr[index] != '\0') {
        if (isspace(pStr[index])) {
            cache.clear();
            pStr[index_insert] = pStr[index];
            ++index_insert;
        } else if (!cache.count(pStr[index])) {
            cache.insert(pStr[index]);
            pStr[index_insert] = pStr[index];
            ++index_insert;
        }

        ++index;
    }
    pStr[index_insert] = '\0';
}

int main()
{
    char *str = strdup("Hello World!!!");
    cout << "orig = " << str << endl;
    RemoveDups(str);
    cout << "modificated = " << str << endl;
    return 0;
}
