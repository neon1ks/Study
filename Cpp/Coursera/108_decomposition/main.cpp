#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType { NewBus, BusesForStop, StopsForBus, AllBuses };

struct Query
{
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream &operator>>(istream &is, Query &q)
{
    string operation_code;
    is >> operation_code;

    if (operation_code == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        size_t stop_count{};
        is >> stop_count;
        q.stops.resize(static_cast<size_t>(stop_count));
        for (string &stop : q.stops) {
            is >> stop;
        }

    } else if (operation_code == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;

    } else if (operation_code == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;

    } else if (operation_code == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }

    return is;
}

struct BusesForStopResponse
{
    vector<string> buses;
};

ostream &operator<<(ostream &os, const BusesForStopResponse &r)
{
    if (r.buses.empty()) {
        os << "No stop";
    } else {
        bool first = true;
        for (const string &bus : r.buses) {
            if (first) {
                first = false;
            } else {
                os << ' ';
            }
            os << bus;
        }
    }
    return os;
}

struct StopsForBusResponse
{
    string bus;
    vector<string> stop_list;
    map<string, vector<string>> stops;
};

ostream &operator<<(ostream &os, const StopsForBusResponse &r)
{
    if (r.stops.empty()) {
        os << "No bus";
    } else {
        //for (const auto &[stop, buses] : r.stops) {
        bool first = true;
        for (const string &stop : r.stop_list) {
            if (first) {
                first = false;
            } else {
                os << '\n';
            }
            os << "Stop " << stop << ':';
                if (r.stops.at(stop).size() == 1) {
                os << " no interchange";
            } else {
                for (const string &other_bus : r.stops.at(stop)) {
                    if (r.bus != other_bus) {
                        os << ' ' << other_bus;
                    }
                }
            }
        }
    }
    return os;
}

struct AllBusesResponse
{
    map<string, vector<string>> buses_to_stops;
};

ostream &operator<<(ostream &os, const AllBusesResponse &r)
{
    if (r.buses_to_stops.empty()) {
        os << "No buses";
    } else {
        for (const auto &bus_item : r.buses_to_stops) {
            os << "Bus " << bus_item.first << ':';
            for (const string &stop : bus_item.second) {
                os << ' ' << stop;
            }
            os << endl;
        }
    }
    return os;
}

class BusManager
{
public:
    void AddBus(const string &bus, const vector<string> &stops)
    {
        buses_to_stops[bus] = stops;
        for (const string &stop : stops) {
            stops_to_buses[stop].push_back(bus);
        }
    }

    [[nodiscard]] BusesForStopResponse GetBusesForStop(const string &stop) const
    {
        BusesForStopResponse result;
        if (stops_to_buses.find(stop) == stops_to_buses.end()) {
            return result;
        }
        result.buses = stops_to_buses.at(stop);
        return result;
        ;
    }

    [[nodiscard]] StopsForBusResponse GetStopsForBus(const string &bus) const
    {
        StopsForBusResponse result;
        result.bus = bus;
        if (buses_to_stops.count(bus) == 0) {
            return result;
        }
        result.stop_list = buses_to_stops.at(bus);
        for (const string &stop : buses_to_stops.at(bus)) {
            result.stops[stop] = stops_to_buses.at(stop);
        }
        return result;
    }

    [[nodiscard]] AllBusesResponse GetAllBuses() const { return { buses_to_stops }; }

private:
    map<string, vector<string>> buses_to_stops;
    map<string, vector<string>> stops_to_buses;
};

#ifdef ONLY_HOME
int main()
{
    int query_count{};
    Query q{};

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(q.bus, q.stops);
            break;
        case QueryType::BusesForStop:
            cout << bm.GetBusesForStop(q.stop) << endl;
            break;
        case QueryType::StopsForBus:
            cout << bm.GetStopsForBus(q.bus) << endl;
            break;
        case QueryType::AllBuses:
            cout << bm.GetAllBuses() << endl;
            break;
        }
    }

    return 0;
}
#endif
