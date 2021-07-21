#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void MoveStrings(vector<string> &source, vector<string> &destination)
{
    //for (auto &w : source) {
    //    destination.push_back(w);
    //}
    copy(source.begin(), source.end(), back_inserter(destination));
    source.clear();
}

void MyPrintVector(const vector<string> &words)
{
    bool first = true;
    for (const auto &w : words) {
        if (first) {
            first = false;
        } else {
            cout << ", ";
        }
        cout << w;
    }
    cout << endl;
}

int main()
{
    vector<string> source = { "a", "b", "c" };
    vector<string> destination = { "z" };
    MoveStrings(source, destination);

    cout << "source = ";
    MyPrintVector(source);

    cout << "destination = ";
    MyPrintVector(destination);
    return 0;
}

/*
void MoveStrings(vector<string>& source, vector<string>& destination) {
  for (auto w : source) {
    destination.push_back(w);
  }
  source.clear();
}
*/
