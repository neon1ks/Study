#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    const string file_name_input{ "input.txt" };
    const string file_name_output{ "output.txt" };
    ifstream input(file_name_input);
    ofstream output(file_name_output);
    string line;
    if (input) {
        while (getline(input, line)) {
            output << line << endl;
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
  ofstream output("output.txt");

  string line;
  while (getline(input, line)) {
    output << line << endl;
  }

  return 0;
}
*/
