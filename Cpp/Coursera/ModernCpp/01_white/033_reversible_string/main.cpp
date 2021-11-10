#include <iostream>
#include <utility>

using namespace std;

class ReversibleString
{
public:
    ReversibleString(string s = "") : text(std::move(s)) { }
    string ToString() const { return text; }
    void Reverse()
    {
        for (size_t i = 0; i < text.size() / 2; ++i) {
            swap(text[i], text[text.size() - 1 - i]);
        }
    }

private:
    string text;
};

int main()
{
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString &s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}

/*
#include <algorithm>
#include <string>

using namespace std;

class ReversibleString {
public:
  ReversibleString() {}
  ReversibleString(const string& s) {
    data = s;
  }
  void Reverse() {
    reverse(begin(data), end(data));
  }
  string ToString() const {
    return data;
  }
private:
  string data;
};
*/
