#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <list>

using namespace std;

// /*
struct CityRecord {
    std::string Name;
    uint64_t Population;
    double Latitutde, Longitude;
};
typedef struct CityRecord NewCityRecord;


int main() {
    std::unordered_map<std::string, NewCityRecord> cityMap;
    cityMap["Melbourne"] = NewCityRecord{"Melbourne", 5000000, 2.4, 9.4};
    cityMap["Lol-town"] = NewCityRecord{"Lol-town", 5000000, 2.4, 9.4};
    cityMap["Berlin"] = NewCityRecord{"Berlin", 5000000, 2.4, 9.4};
    cityMap["Paris"] = NewCityRecord{"Paris", 5000000, 2.4, 9.4};
    cityMap["London"] = NewCityRecord{"London", 5000000, 2.4, 9.4};

    cityMap.insert({"Singapore", NewCityRecord{"Singapore", 20'000'000, 2.4, 9.4}});
    cityMap.emplace("Gotham", NewCityRecord{"Gotham", 21'054'009, 2.4, 9.4});

    for (auto it = cityMap.begin(); it != cityMap.end(); it++)
        std::cout << (it->second).Name << ", ";

    std::cout << std::endl << cityMap["Gotham"].Population;
}
// */


/*
int main() {
  map<int, string> sample_map;
  sample_map.insert(pair<int, string>(1, "one"));
  sample_map.insert(pair<int, string>(2, "two"));

  cout << sample_map[1] << " " << sample_map[2] << endl;
}
*/


// CodeBeauty Maps Video: English -> German Translation
/*
int main() {
    std::unordered_map<std::string, std::string> myDictionary;
    myDictionary.insert({"apple", "der Apfel"});
    myDictionary.insert({"banana", "der die Banane"});
    myDictionary.insert({"orange", "die Orange, die Apfelsine"});
    myDictionary.insert({"strawberry", "die Erdbeere"});

    myDictionary["beets"] = "lol";

    myDictionary.insert({"pear", "adcsfbhl"});

    // for(std::unordered_map<std::string, std::string>::const_iterator it = myDictionary.cbegin(); it != myDictionary.cend(); it++) {
    //     std::cout << "Key: " << it->first << "\t\tValue: " << it->second << std::endl;
    // }
    for(auto pair : myDictionary)
        std::cout << "Key: " << pair.first << "\t\tValue: " << pair.second << std::endl;

}
*/


/*
int main() {
    map<string, list<string>> pokedex;

    list<string> pikachuAttacks{"thunder shock", "tail whip", "quick attack"};
    list<string> charmaderAttacks{"flame thrower", "scary face"};
    list<string> chikoritaAttacks{"razor leaf", "poison powder"};

    pokedex.emplace("Pikatchu", pikachuAttacks);
    pokedex.emplace("Charmander", charmaderAttacks);
    pokedex.emplace("Chikortia", chikoritaAttacks);


    for (auto pokemon : pokedex) {
        cout << pokemon.first << "\t-\t";

        for (list<string>::iterator attack = pokemon.second.begin(); attack != pokemon.second.end(); attack++) {
            cout << *attack;

            // Look at the next element in the list to see whether to place full stop or comma
            auto next_attack = next(attack);
            if (next_attack == pokemon.second.end())
                cout << ".";
            else
                cout << ", ";
        }
        cout << endl;
    }
}
*/