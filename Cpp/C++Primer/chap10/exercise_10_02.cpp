#include <iostream>
#include <string>
#include <list>
#include <algorithm>

int main() {
	std::list<std::string> ls;

	std::string temp;
	while(std::getline(std::cin, temp)) {
		ls.push_back(temp);
	}

	std::string val = "test";
	auto c = std::count(ls.cbegin(), ls.cend(), val);
	
	std::cout << "val = " << c << std::endl;

	return 0;
}
