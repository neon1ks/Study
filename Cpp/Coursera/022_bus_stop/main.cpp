#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    size_t count = 0;
    cin >> count;

    vector<string> bus_names;
    map<string, vector<string>> busMap;
    for (size_t i = 0; i < count; ++i) {
        static string cmd;
        cin >> cmd;
        if (cmd == "NEW_BUS") {
            string bus_name;
            size_t stop_count = 0;
            cin >> bus_name >> stop_count;
            bus_names.push_back(bus_name);
            for (size_t j = 0; j < stop_count; ++j) {
                static string stop;
                cin >> stop;
                busMap[bus_name].push_back(stop);
            }
        } else if (cmd == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            bool first = true;
            for (const auto &bus_name : bus_names) {
                if (find(begin(busMap[bus_name]), end(busMap[bus_name]), stop)
                        != end(busMap[bus_name])) {
                    if (first) {
                        first = false;
                    } else {
                        cout << ' ';
                    }
                    cout << bus_name;
                }
            }

            for (const auto &bus : busMap) { }
            if (first) {
                cout << "No stop";
            }
            cout << endl;
        } else if (cmd == "STOPS_FOR_BUS") {
            string bus_name;
            cin >> bus_name;
            if (busMap.find(bus_name) == busMap.end()) {
                cout << "No bus" << endl;
            } else {

                for (const auto &stop : busMap[bus_name]) {
                    cout << "Stop " << stop << ':';
                    bool finded = false;
                    for (const auto &name : bus_names) {
                        if (name != bus_name) {
                            if (find(begin(busMap[name]), end(busMap[name]),
                                        stop)
                                    != end(busMap[name])) {
                                cout << ' ' << name;
                                finded = true;
                            }
                        }
                    }
                    if (!finded) {
                        cout << " no interchange";
                    }
                    cout << endl;
                }
            }
        } else if (cmd == "ALL_BUSES") {
            if (busMap.empty()) {
                cout << "No buses" << endl;
            } else {
                for (const auto &bus : busMap) {
                    cout << "Bus " << bus.first << ':';
                    for (const auto &stop : bus.second) {
                        cout << ' ' << stop;
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}

/*
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// ответ на запрос BUSES_FOR_STOP
void PrintBusesForStop(map<string, vector<string>>& stops_to_buses,
    const string& stop) {
    if (stops_to_buses.count(stop) == 0) {
        cout << "No stop" << endl;
    } else {
        for (const string& bus : stops_to_buses[stop]) {
            cout << bus << " ";
        }
        cout << endl;
    }
}

// ответ на запрос STOPS_FOR_BUS
void PrintStopsForBus(map<string, vector<string>>& buses_to_stops,
    map<string, vector<string>>& stops_to_buses,
    const string& bus) {
    if (buses_to_stops.count(bus) == 0) {
        cout << "No bus" << endl;
    } else {
        for (const string& stop : buses_to_stops[bus]) {
            cout << "Stop " << stop << ": ";

            // если через остановку проходит ровно один автобус,
            // то это наш автобус bus, следовательно, пересадки тут нет
            if (stops_to_buses[stop].size() == 1) {
                cout << "no interchange";
            } else {
                for (const string& other_bus : stops_to_buses[stop]) {
                    if (bus != other_bus) {
                        cout << other_bus << " ";
                    }
                }
            }
            cout << endl;
        }
    }
}

// ответ на запрос ALL_BUSES
void PrintAllBuses(const map<string, vector<string>>& buses_to_stops) {
    if (buses_to_stops.empty()) {
        cout << "No buses" << endl;
    } else {
        for (const auto& bus_item : buses_to_stops) {
            cout << "Bus " << bus_item.first << ": ";
            for (const string& stop : bus_item.second) {
                cout << stop << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int q;
    cin >> q;

    map<string, vector<string>> buses_to_stops, stops_to_buses;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "NEW_BUS") {

            string bus;
            cin >> bus;
            int stop_count;
            cin >> stop_count;

            // с помощью ссылки дадим короткое название вектору
            // со списком остановок данного автобуса;
            // ключ bus изначально отсутствовал в словаре, поэтому он автоматически
            // добавится туда с пустым вектором в качестве значения
            vector<string>& stops = buses_to_stops[bus];
            stops.resize(stop_count);

            for (string& stop : stops) {
                cin >> stop;
                // не забудем обновить словарь stops_to_buses
                stops_to_buses[stop].push_back(bus);
            }

        } else if (operation_code == "BUSES_FOR_STOP") {

            string stop;
            cin >> stop;
            PrintBusesForStop(stops_to_buses, stop);

        } else if (operation_code == "STOPS_FOR_BUS") {

            string bus;
            cin >> bus;
            PrintStopsForBus(buses_to_stops, stops_to_buses, bus);

        } else if (operation_code == "ALL_BUSES") {

            PrintAllBuses(buses_to_stops);

        }
    }

    return 0;
}
*/
