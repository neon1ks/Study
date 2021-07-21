#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

//При поиске upper_bound для значения 5 это будет итератор на значение 6
// - первое большее значение.

// Соответственно, lower_bound будет указывать на первое не меньшее значение
// - на первое 5.

// lower_bound(k) - возвращает итератор на первый элемент, значение ключа которого больше, чем k
// upper_bound(k) - Возвращает итератор на первый элемент, значение ключа которого больше, чем k


int main() {
	std::vector<int> a = {1,2,3,4,5,6,7,8,9,10,10,11,11,12,16,20,20,20,20,21};
	
	for(auto p = std::lower_bound(a.cbegin(), a.cend(), 10);
		p != std::upper_bound(a.cbegin(), a.cend(),20); ++p) {
			std::cout << *p << ' ';
	}
	// 10 10 11 11 12 16 20 20 20 20 
	std::cout << std::endl;
	
		for(auto p = std::lower_bound(a.cbegin(), a.cend(), 10,
										[](int value, int point) { 
											return value <= point; 
											});
		p != std::upper_bound(a.cbegin(), a.cend(),20); ++p) {
			std::cout << *p << ' ';
	}
	std::cout << std::endl;
	// 11 11 12 16 20 20 20 20
	
	
	size_t i_start{};
	size_t i_end{};
	
	cout << "Use lambda with <=" << endl;
	auto it_lower = std::lower_bound(a.cbegin(), a.cend(), 10,
			[](int value, int point) { return value <= point; });
	auto it_upper = std::upper_bound(a.cbegin(), a.cend(), 10,
			[](int value, int point) { return value <= point; });
	i_start = static_cast<size_t>(it_lower - a.cbegin());
	i_end = static_cast<size_t>(it_upper - a.cbegin());
	cout << "i_start = " << i_start << endl;
	cout << "i_end = " << i_end << endl;
	std::cout << std::endl;
	
	
	cout << "Use lambda with <" << endl;
	it_lower = std::lower_bound(a.cbegin(), a.cend(), 10,
			[](int value, int point) { return value < point; });
	it_upper = std::upper_bound(a.cbegin(), a.cend(), 10,
			[](int value, int point) { return value < point; });
	i_start = static_cast<size_t>(it_lower - a.cbegin());
	i_end = static_cast<size_t>(it_upper - a.cbegin());
	cout << "i_start = " << i_start << endl;
	cout << "i_end = " << i_end << endl;
	std::cout << std::endl;
	
	
	cout << "Use default" << endl;
	it_lower = std::lower_bound(a.cbegin(), a.cend(), 10);
	it_upper = std::upper_bound(a.cbegin(), a.cend(), 10);
	i_start = static_cast<size_t>(it_lower - a.cbegin());
	i_end = static_cast<size_t>(it_upper - a.cbegin());
	cout << "i_start = " << i_start << endl;
	cout << "i_end = " << i_end << endl;
	std::cout << std::endl;
	
	return 0;
}
