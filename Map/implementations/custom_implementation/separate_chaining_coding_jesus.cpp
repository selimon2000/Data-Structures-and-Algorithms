// Tutorial I am using: 
// https://www.youtube.com/watch?v=2_3fR-k-LzI&ab_channel=CodingJesus


// Using Separate Chaining
// Hashtable to implement a phone book
//   Where phone number is 3 letters, and there is a name associated with the phone number
// Key-value Pair: Key will be an integer type, and value will be of string type

#include <iostream>
#include <list> // Linked List Abstract data type

class HashTable {
    private:
        static const int hashGroups = 10;
        // Int refers to number, string refers to name of person. E.g. 905, Jimmy
        typedef std::list<std::pair<int, std::string>> hash_table;
        hash_table table[hashGroups]; // there is a doubly linked list of pairs

    public:
        bool isEmpty();
        int hashFunction(int key);
        void insertItem(int key, std::string value);
        void removeItem(int key);
        std::string searchTable (int key);
        void printTable();
};


bool HashTable::isEmpty() {
    for (int i = 0; i < hashGroups; i++) {
        if (table[i].empty())
            return true;
    }
    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups; // If key = 905, function will spit out 5.
}

void HashTable::insertItem(int key, std::string value) {
    int index = hashFunction(key);

    // First check if this key exists or not
    for (hash_table::iterator it = table[index].begin(); it != table[index].end(); it++) {
        if (it->first == key) {
            it->second = value;
            std::cout << "[WARNING] Key already exists. Value Updated." << std::endl;
            return;
        }
    }

    table[index].emplace_back(key, value);
}

void HashTable::removeItem(int key) {
    int index = hashFunction(key);

    for (hash_table::iterator it = table[index].begin(); it != table[index].end(); it++) {
        if (key == it->first) {
            table[index].erase(it);
            return;
        }
    }

    std::cout << "[WARNING] Could not Find item so removeItem failed" << std::endl;
}

void HashTable::printTable() {
    std::cout << "Printing Table:" << std::endl;
    for (int index = 0; index < hashGroups; index++) {
        for (hash_table::iterator it = table[index].begin(); it != table[index].end(); it++) {
            std::cout << "First: " << it->first << ", Second: " << it->second << std::endl;
        }
    }   
    std::cout << std::endl;
}

std::string HashTable::searchTable(int key) {
    int index = hashFunction(key);

    for (auto it = table[index].cbegin(); it != table[index].cend(); it++) {
        if (it->first == key) {
            return it->second;
        }
    }
    std::cout << "Search failed" << std::endl;
    return "";
}

int main() {
    HashTable my_hashtable;
    my_hashtable.printTable();

    my_hashtable.insertItem(333, "Selimon");
    my_hashtable.printTable();

    my_hashtable.insertItem(333, "Selimon");
    my_hashtable.insertItem(434, "Subhan");
    my_hashtable.insertItem(1234, "Diba");
    my_hashtable.insertItem(123432, "Suleman");
    my_hashtable.printTable();

    my_hashtable.removeItem(333);
    my_hashtable.printTable();

    std::cout << "Search Table: " << my_hashtable.searchTable(1234) << std::endl;
}