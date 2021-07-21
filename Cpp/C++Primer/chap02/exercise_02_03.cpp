#include <iostream>

using namespace std;

int main()
{
	unsigned u = 10, u2 = 42;
	std::cout << u2 -u << std::endl;
	std::cout << u - u2 << std::endl;
	int i1 = 10, i2 = 42;
	std::cout << i2 - i1 << std::endl;
	std::cout << i1 - i2 << std::endl;
	std::cout << i1 - u << std::endl;
	std::cout << u - i1 << std::endl;

	return 0;
}

