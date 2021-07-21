#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

struct City
{
    int x;
    int y;
};

class TNode final
{
public:
    explicit TNode(unsigned int key, TNode *parent = nullptr)
        : m_key(key), m_parent(parent)
    {
    }
    TNode(const TNode &) = delete;
    TNode &operator=(const TNode &str) = delete;
    ~TNode()
    {
        for (auto &c : m_children) {
            delete c;
        }
    }

    unsigned int m_key;
    TNode *m_parent;
    std::vector<TNode *> m_children;

    TNode *Insert(unsigned int key)
    {
        auto *child = new TNode(key, this);
        m_children.push_back(child);
        return child;
    }

    int Level()
    {
        int l = 1;
        TNode *parent = m_parent;
        while (parent) {
            ++l;
            parent = parent->m_parent;
        }
        return l;
    }

    void DelChild(TNode *child)
    {
        auto it = std::find(m_children.begin(), m_children.end(), child);
        m_children.erase(it);
        delete child;
    }
};

void DeleteChildren(TNode *child)
{
    TNode *parent = child->m_parent;
    while (parent && parent->m_children.empty()) {
        parent->DelChild(child);
        child = parent;
        parent = child->m_parent;
    }
}

bool checkDist(const std::vector<City> &cities, long long maxDist,
        unsigned int curr, unsigned int end,
        std::vector<unsigned int> &visitCities)
{
    for (const auto v : visitCities) {
        if (cities[v].x == cities[end].x && cities[v].y == cities[end].y) {
            return false;
        }
    }

    long long dist =
            std::abs(static_cast<long long>(cities[curr].x) - cities[end].x)
            + std::abs(static_cast<long long>(cities[curr].y) - cities[end].y);

    if (maxDist < dist) {
        return false;
    }
    return true;
}

int main()
{

    int minDist = -1;
    unsigned int count{};
    std::cin >> count;

    std::vector<City> cities(count);
    for (unsigned int i = 0; i < count; ++i) {
        std::cin >> cities[i].x >> cities[i].y;
    }

    long long maxDist{};
    unsigned int start{};
    unsigned int end{};

    std::cin >> maxDist;
    std::cin >> start >> end;
    --start;
    --end;

    std::vector<unsigned int> visitCities{ start };
    std::queue<TNode *> lastCities;
    auto *root = new TNode{ start };
    lastCities.push(root);

    while (!lastCities.empty()) {

        TNode *now = lastCities.front();
        lastCities.pop();

        if (checkDist(cities, maxDist, now->m_key, end, visitCities)) {
            minDist = now->Level();
            break;
        }

        bool addFlag = false;
        for (unsigned int i = 0; i < cities.size(); ++i) {
            if (checkDist(cities, maxDist, now->m_key, i, visitCities)) {
                TNode *child = now->Insert(i);
                lastCities.push(child);
                visitCities.push_back(i);
                addFlag = true;
            }
        }
        if (!addFlag) {
            DeleteChildren(now);
        }
    }

    delete root;
    root = nullptr;

    std::cout << minDist << std::endl;

    return 0;
}
