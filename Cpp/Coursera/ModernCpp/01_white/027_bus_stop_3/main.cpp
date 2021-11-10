#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    map<set<string>, size_t> bus_stops;
    size_t n = 0;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        size_t count = 0;
        cin >> count;
        set<string> bus;
        for (size_t j = 0; j < count; ++j) {
            string stop;
            cin >> stop;
            bus.insert(stop);
        }
        if (bus_stops.find(bus) == bus_stops.end()) {
            auto bus_size = bus_stops.size();
            bus_stops[bus] = bus_size + 1;
            cout << "New bus " << bus_size + 1 << endl;
        } else {
            cout << "Already exists for " << bus_stops[bus] << endl;
        }
    }
    return 0;
}

/*
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main() {
    int q;
    cin >> q;

    map<set<string>, int> buses;

    for (int i = 0; i < q; ++i) {
        int n;
        cin >> n;
        set<string> stops;
        for (int j = 0; j < n; ++j) {
            string stop;
            cin >> stop;
            stops.insert(stop);
        }
        if (buses.count(stops) == 0) {
            const int new_number = buses.size() + 1;
            buses[stops] = new_number;
            cout << "New bus " << new_number << endl;
        } else {
            cout << "Already exists for " << buses[stops] << endl;
        }
    }

    return 0;
}
*/
