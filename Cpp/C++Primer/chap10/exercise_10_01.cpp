#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> v;
	int temp;
	while (std::cin >> temp) {
		v.push_back(temp);
	}
	
	for (const auto &e: v) {
		std::cout << e << ' ';
	}
	std::cout << std::endl;
	
	int val = 5;
	auto c = std::count(v.cbegin(), v.cend(), val);
	
	std::cout << "count = " << c << std::endl;
	return 0;
}
