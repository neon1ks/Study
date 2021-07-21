#include <iostream>
#include <set>

using std::cin;
using std::cout;


int main() {

	int temp{};
	std::set<int> setInt;

	std::size_t count{};


	cin >> count;

	while (count > 0) {
		cin >> temp;
		setInt.insert(temp);
    	--count;
	}
for (const auto &e: setInt) {
    cout << e << std::endl;
}

    return 0;
}
