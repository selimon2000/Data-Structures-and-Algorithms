#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdint>

using namespace std;


struct CityRecord {
    string Name;
    uint64_t Population;
    double Latitude, Longitude;

    CityRecord(){}
    CityRecord(const string &name, uint64_t pop, double lat, double lon) : Name(name), Population(pop), Latitude(lat), Longitude(lon) {}
};


int main() {
    unordered_map<string, CityRecord> cityMap;

    cityMap["Melbourne"] = CityRecord{"Melbourne", 5000000, 2.4, 9.4};
    
    cityMap.emplace(piecewise_construct, forward_as_tuple("Rockdale"), forward_as_tuple("Rockdale", 200000, 2.4, 9.4));
    
    for (auto it = cityMap.cbegin(); it != cityMap.cend(); ++it)
        cout << it->first << '\t' << it->second.Name << '\n';
}