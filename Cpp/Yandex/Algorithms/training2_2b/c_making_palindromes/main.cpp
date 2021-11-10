#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    cin >> word;
    size_t i = 0;
    size_t j = word.size() - 1;
    size_t count = 0;
    while (i < j) {
        if (word[i] != word[j]) {
            ++count;
        }
        ++i;
        --j;
    }
    cout << count << endl;
    return 0;
}
