#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main() {
	
	vector<string> vec;
	string temp;
	
	while(cin >> temp) {
		vec.push_back(temp);
	}

	stable_sort(vec.begin(), vec.end(), isShorter);
	
	cout << "\nSorted:" << endl;
	for (const auto s: vec) {
		cout << s << endl;
		
	}

	return 0;
}
