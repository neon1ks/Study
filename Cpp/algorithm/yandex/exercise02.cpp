#include <iostream>


using std::cin;
using std::cout;


int main() {

	int temp{};
	std::size_t now{};
	std::size_t count{};
	std::size_t result{};

	cin >> count;

	while (count > 0) {
		cin >> temp;

		if (temp == 1) {
    		++now;
			result = std::max(now, result);
        } else {
        	now = 0;
        }
    	--count;
	}

    cout << result;

    return 0;
}
