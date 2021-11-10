#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    const string file_name{ "input.txt" };
    ifstream input(file_name);
    string line;
    if (input) {
        while (getline(input, line)) {
            cout << line << endl;
        }
    }
    return 0;
}

/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream input("input.txt");

  string line;
  while (getline(input, line)) {
    cout << line << endl;
  }

  return 0;
}
*/
