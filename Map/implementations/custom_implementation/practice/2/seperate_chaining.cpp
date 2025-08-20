#include <iostream>
#include <forward_list>

#define table_size 10


class HashTable {
private:
    std::forward_list<std::pair<int, std::string>> hash_table[table_size];
    int hashFunction(int key);

public:
    void insert(int key, std::string value);
    void removeItem(int key);

    std::string searchTable(int key);

    void printTable();
};

int HashTable::hashFunction(int key) {
    int sum = 0;
    for (; key > 0; key /= 10)
        sum += key % 10;
    
    return sum % table_size;
}

void HashTable::insert(int key, std::string value) {
    int pos = this->hashFunction(key);
    hash_table[pos].push_front({key,value});
}

void HashTable::removeItem(int key) {
    int pos = this->hashFunction(key);
    if (hash_table[pos].empty())
        return;
    
    hash_table[pos].pop_front();
}

std::string HashTable::searchTable(int key) {
    int pos = this->hashFunction(key);
    for (auto node : hash_table[pos]) {
        if (node.first == key)
            return node.second;
    }
    
    std::cout << "[WARNING]\tKey Not Found" << std::endl;
    return "";
}

void HashTable::printTable() {
    std::cout << "Printing Table:" << std::endl;
    for (auto list : hash_table) {
        for (auto node : list)
            std::cout << "Key: " << node.first << "\tValue: " << node.second << std::endl;        
    }
    std::cout << std::endl;
}


int main() {
    HashTable my_hashtable;
    my_hashtable.printTable();

    my_hashtable.insert(333, "Selimon");
    my_hashtable.printTable();

    my_hashtable.insert(333, "Selimon");
    my_hashtable.insert(434, "Subhan");
    my_hashtable.insert(1234, "Diba");
    my_hashtable.insert(123432, "Suleman");
    my_hashtable.printTable();

    std::cout << "Table after removing element:" << std::endl;
    my_hashtable.removeItem(333);
    my_hashtable.printTable();

    std::cout << "Search Table: " << my_hashtable.searchTable(1234) << std::endl;
}