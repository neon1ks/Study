#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

struct City {
	long long x;
	long long y;
};


class TNode final{
public:
	explicit TNode(std::size_t key, TNode * parent = nullptr)
		: m_key(key), m_parent(parent) {}
	TNode(const TNode &) = delete;
	TNode &operator=(const TNode &str) = delete;
	~TNode() {
		for (auto &c : m_childs) {
			delete c;
		}
	}

	std::size_t m_key;
	TNode* m_parent;
	std::vector<TNode *> m_childs;

	TNode *Insert(std::size_t key) {
		auto* child = new TNode(key, m_parent);
		m_childs.push_back(child);
		return child;
	}

	TNode * GetParent() const{
		return m_parent;
	}
	
	int Level() const {
		int l = 1;
		TNode *parent = m_parent;
		while (!parent) {
			++l;
			parent = parent->GetParent();
		}
		return l;
	}

};

bool checkDist(const std::vector<City> &cities,
			   long long maxDist,
			   TNode *paths,
			   std::size_t end)
{
	TNode *prev = paths;
	while (!prev) {
		if (cities[prev->m_key].x == cities[end].x
		      && cities[prev->m_key].y == cities[end].y)
		{
			return false;
		}
		prev = prev->GetParent();
	}
	std::size_t last = paths->m_key;
	long long dist = std::abs(cities[last].x - cities[end].x)
				+ std::abs(cities[last].y - cities[end].y);

	if (maxDist < dist) {
		return false;
	}
	return true;
}


int main() {

	int minDist = -1;
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

	std::cout << "Start" << std::endl; 

	std::queue<TNode *> lastCities;
	TNode *root = new TNode{start};
	lastCities.push(root);

	while (!lastCities.empty()) {
		
		TNode *now = lastCities.front();
		
		if (checkDist(cities, maxDist, now, end )) {
			minDist = now->Level();
			break;
		}
		
		for(std::size_t i = 0; i < cities.size(); ++i) {
			if (checkDist(cities, maxDist, now, i )) {
				TNode *child = now->Insert(i);
				lastCities.push(child);
			}
		}
	}

	std::cout << minDist << std::endl;

	return 0;
}
