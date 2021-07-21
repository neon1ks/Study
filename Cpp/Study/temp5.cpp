#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

struct City {
	long long x;
	long long y;
};

static int minDist = {};

bool checkDist(const std::vector<City> &cities,
			   long long maxDist,
			   const std::vector<std::size_t> &prev,
			   std::size_t end) {
	for (const auto p : prev) {
		if (cities[p].x == cities[end].x && cities[p].y == cities[end].y) {
			return false;
		}
	}
	std::size_t last = prev.back();
	long long dist = std::abs(cities[last].x - cities[end].x)
				+ std::abs(cities[last].y - cities[end].y);

	if (maxDist < dist) {
		return false;
	}
	return true;
}

int findDist(const std::vector<City> &cities,
			   long long maxDist,
			   std::vector<std::size_t> &paths,
			   std::size_t end) {

	if (checkDist(cities, maxDist, paths, end )) {
		minDist = std::min(minDist, static_cast<int>(paths.size()));
		return -1;
	} else {
		for(std::size_t i = 0; i < cities.size(); ++i) {
			if (checkDist(cities, maxDist, paths, i )) {
				paths.push_back(i);
				auto f = findDist(cities, maxDist, paths, end );
				if (f > 0) {
					return f;
				}
				paths.erase(paths.end()-1);
			}
		}
	}
	return -1;
}

int main() {

	minDist = std::numeric_limits<int>::max();
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

	std::vector<std::size_t> paths = {start};
	findDist(cities, maxDist, paths, end );

if (minDist == std::numeric_limits<int>::max()) {
	minDist = -1;
}

	std::cout << minDist << std::endl;

	return 0;
}
