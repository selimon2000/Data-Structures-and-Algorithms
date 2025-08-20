// WITHOUT TEMPLATE ////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// #include <forward_list>

// #define size 10


// namespace dsa {
// typedef std::pair<int, std::string> i_n_pair;

// // Hashtable using Seperate Chaining
// // Maps Employee ID number to Full Name
// class HashTable
// {
// public:
//     HashTable() {}
//     ~HashTable() {}
    
//     void insert(const i_n_pair &new_pair);
//     void remove(int key);
//     void printTable();


// private:
//     std::forward_list<i_n_pair> i_n[size]; // i_n means Id emplyee N
//     int hashFunction(int id);
// };


// int HashTable::hashFunction(int id) {
//     int sum = 0;
//     while(id) {
//         sum += (id % 10) * 7;
//         id /= 10;
//     }
//     return sum % size;
// }

// void HashTable::insert(const i_n_pair &new_pair) {
//     int index = hashFunction(new_pair.first);
//     // Check if key already exists
//     for (i_n_pair _pair : i_n[index]) {
//         if (new_pair.first == _pair.first) {
//             std::cout << "[WARNING]\tKey " << new_pair.first << " already exists" << std::endl;
//             return;
//         }
//     }

//     i_n[index].emplace_front(new_pair);
// }

// void HashTable::remove(int key) {
//     int hashed_key = hashFunction(key);

//     for (auto it = i_n[hashed_key].before_begin(); std::next(it) != i_n[hashed_key].end(); it++) {
//         if(std::next(it)->first == key) {
//             i_n[hashed_key].erase_after(it);
//             return;
//         }
//     }
//     std::cout << "[WARNING]\tKey does not exist so cannot be removed" << std::endl;
// }

// void HashTable::printTable() {
//     for (int i = 0; i < size; i++)
//         for(i_n_pair _pair : i_n[i])
//             std::cout << "Key: " << _pair.first << "\tValue: " << _pair.second << std::endl;

//     std::cout << std::endl;
// }

// }


// int main() {
//     dsa::HashTable my_hashtable;
//     my_hashtable.printTable();


//     my_hashtable.insert({10008202, "Selimon Shukurzad"});
//     my_hashtable.insert({333, "Selimon"});
//     my_hashtable.insert({434, "Subhan"});
//     my_hashtable.insert({1234, "Diba"});
//     my_hashtable.insert({123432, "Suleman"});

//     my_hashtable.printTable();

//     my_hashtable.remove(333);
//     std::cout << "Table after removing element:" << std::endl;
//     my_hashtable.printTable();
// }


// WITH TEMPLATE ////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <forward_list>

#define size 10


namespace dsa {

// Hashtable using Seperate Chaining
// Maps Employee ID number to Full Name
template <class K, class V>
class HashTable {
    
using i_n_pair = std::pair<K, V>;
// typedef std::pair<int, std::string> i_n_pair;

public:
    HashTable() {}
    ~HashTable() {}
    
    void insert(const i_n_pair &new_pair);
    void remove(const K &key);
    void printTable();


private:
    std::forward_list<i_n_pair> i_n[size]; // Array of forward_lists
    
    // int hashFunction(const K id);
    int hashFunction(const int key);
    int hashFunction(const std::string &key);
};

template <typename K, typename V>
int HashTable<K, V>::hashFunction(const int key) {
    return key % size;
}

template <typename K, typename V>
int HashTable<K, V>::hashFunction(const std::string &key) {
    int hash = 0;
    for (char ch : key) {
        hash = (hash * 31 + ch) % size; // A simple hash function for strings
    }
    return hash;
}

template <typename K, typename V>
void HashTable<K, V>::insert(const i_n_pair &new_pair) {
    int index = hashFunction(new_pair.first);
    // Check if key already exists
    for (const i_n_pair& _pair : i_n[index]) {
        if (new_pair.first == _pair.first) {
            std::cout << "[WARNING]\tKey " << new_pair.first << " already exists" << std::endl;
            return;
        }
    }

    i_n[index].emplace_front(new_pair);
}


template <typename K, typename V>
void HashTable<K, V>::remove(const K& key) {
    int hashed_key = hashFunction(key);

    for (auto it = i_n[hashed_key].before_begin(); std::next(it) != i_n[hashed_key].end(); ++it) {
        if (std::next(it)->first == key) {
            i_n[hashed_key].erase_after(it);
            return;
        }
    }
    std::cout << "[WARNING]\tKey does not exist so cannot be removed" << std::endl;
}

template <typename K, typename V>
void HashTable<K,V>::printTable() {
    for (int i = 0; i < size; ++i)
        for (const i_n_pair &_pair : i_n[i])
            std::cout << "Key: " << _pair.first << "\tValue: " << _pair.second << std::endl;

    std::cout << std::endl;
}

}


int main() {
    dsa::HashTable<int, std::string> my_hashtable;
    my_hashtable.printTable();

    my_hashtable.insert({10008202, "Selimon Shukurzad"});
    my_hashtable.insert({333, "Selimon"});
    my_hashtable.insert({434, "Subhan"});
    my_hashtable.insert({434, "Diba"});
    my_hashtable.insert({123432, "Suleman"});

    my_hashtable.printTable();

    my_hashtable.remove(333);
    std::cout << "Table after removing element:" << std::endl;
    my_hashtable.printTable();
}


// int main() {
//     dsa::HashTable<std::string, std::string> my_hashtable;
//     my_hashtable.printTable();

//     my_hashtable.insert({"1", "Selimon Shukurzad"});
//     my_hashtable.insert({"2", "Selimon"});
//     my_hashtable.insert({"3", "Subhan"});
//     my_hashtable.insert({"3", "Diba"});
//     my_hashtable.insert({"4", "Suleman"});

//     my_hashtable.printTable();

//     my_hashtable.remove("3");
//     std::cout << "Table after removing element:" << std::endl;
//     my_hashtable.printTable();
// }