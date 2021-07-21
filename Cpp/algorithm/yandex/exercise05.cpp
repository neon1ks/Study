#include <iostream>
#include <string>
#include <map>


void CountChar(const std::string &line, std::map<char, std::size_t> &m) {

	for (const auto &ch : line) {
		++m[ch];
	}


}


int main() {


std::string line1;
std::string line2;

std::getline(std::cin, line1);
std::getline(std::cin, line2);

std::map<char, std::size_t> m1;
std::map<char, std::size_t> m2;

CountChar(line1, m1);
CountChar(line2, m2);



	std::cout << (m1 == m2) << std::endl;
return 0;

}
