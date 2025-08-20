#include <unordered_map>
#include <iostream>

using namespace std;


int main() {
    unordered_map<int, int> my_map{{1, 99}, {200, 100}, {3, 101}, {4, 601}};
    my_map.insert({3, 102});
    my_map.insert({3, 102});

    for (auto p : my_map)
        cout << p.first << '\t' << p.second << '\n';
    
    cout << "Number of elements with value of 3: " << my_map.count(3) << '\n';

    // auto range = my_map.equal_range(3);
    // if (range.first != range.second) {
    //     cout << "\n\nElements with key 3:\n";
    //     // for (auto it = range.first; it != range.second; ++it)
    //     //     cout << it->first << " " << it->second << endl;
    // }
    // else cout << "No elements with key 3 found" << endl;

}