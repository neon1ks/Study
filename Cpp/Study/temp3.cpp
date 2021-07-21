#include <iostream>
#include <vector>
#include <queue>

struct City {
	int x;
	int y;
};

bool check(const std::vector<City> &cities,
           long long maxDist,
           const std::vector<std::size_t> &prev,
           std::size_t end) {
	for (const auto p : prev) {
		if (cities[p].x == cities[end].x && cities[p].y == cities[end].y) {
			return false;
		}
	}
	std::size_t last = prev.back();
	long long dist = std::abs(static_cast<long long>(cities[last].x) - cities[end].x)
    			+ std::abs(static_cast<long long>(cities[last].y) - cities[end].y);

	if (maxDist < dist) {
		return false;
	}

	return true;

}

int main() {


	std::size_t count{};
	std::cin >> count;

	std::vector<City> cities(count);
	for (std::size_t i = 0; i < count; ++i) {
		std::cin >> cities[i].x >> cities[i].y;
	}

	long long maxDist{};
	size_t start{}, end{};
	
	std::cin >> maxDist;
	std::cin >> start >> end;
	--start;
	--end;

	std::vector<std::size_t> prev = {start};
	std::queue<std::vector<std::size_t>> paths;
	paths.push(prev);

	bool found = false;

	while (!paths.empty()) {
		std::vector<std::size_t> prev = paths.front();
		paths.pop();

		if (check(cities, maxDist, prev, end )) {
			std::cout << prev.size() << std::endl;
    		found = true;
    		break;
		} else {
    		for(std::size_t i = 0; i < count; ++i) {
    			if (check(cities, maxDist, prev, i )) {
            		std::vector<std::size_t> newPath = {prev};
            		newPath.push_back(i);
            		paths.push(newPath);
            	}
    		}
		}
	}

	if (!found) {
		std::cout << -1 << std::endl;
	}

	

	return 0;
}
