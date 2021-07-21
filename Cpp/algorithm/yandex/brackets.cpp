#include <iostream>
#include <string>

using namespace std;

void generate(std::string cur, size_t open, size_t closed, size_t n) {
	
	if (cur.size() == 2 * n) {
		if (open == closed) {
			cout << cur << endl;
		}
		return;
	}
	generate(cur + '(', open + 1, closed, n);
	if (closed < open) {
		generate(cur + ')', open, closed + 1, n);
	}
}

void generate2(std::string cur, size_t open, size_t closed, size_t n) {
	
	if (cur.size() == 2 * n) {
		cout << cur << endl;
		return;
	}
	if (open < n) {
		generate(cur + '(', open + 1, closed, n);
	}
	if (closed < open) {
		generate(cur + ')', open, closed + 1, n);
	}
}

int main()
{
	size_t n{};
	if (cin >> n) {
		std::string cur;
		generate(cur, 0, 0, n);
		cout << "test" << endl;
		generate2(cur, 0, 0, n);
	}
	return 0;
}

