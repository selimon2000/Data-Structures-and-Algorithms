#include <iostream>
#include <forward_list>

#define table_size 10


class HashTable
{
private:
    std::forward_list<std::pair<int, std::string>> hash_table[table_size];

    int hashFunction(int key);

public:
    HashTable(){}

    void insert(int key, std::string value);
    void removeItem(int key);

    bool isEmpty();
    std::string searchTable(int key);

    void printTable();
};

int HashTable::hashFunction(int key) {
    int sum = 0;
    while (key > 0) {
        sum += (key % 10) * 33;
        key /= 10;
    }
    sum %= table_size;

    return sum;
}

void HashTable::insert(int key, std::string value) {
    int index = hashFunction(key);

    for (auto it = hash_table[index].begin(); it != hash_table[index].end(); it++) {
        if (it->first == key) {
            std::cout << "[WARNING]\tKey already exists" << std::endl;
            return;
        }
    }

    hash_table[index].emplace_front(key, value);
}

void HashTable::removeItem(int key) {
    int index = hashFunction(key);

    auto prev = hash_table[index].before_begin();
    auto it = hash_table[index].begin();
    for (; it != hash_table[index].end(); it++, prev++) {
        if (it->first == key)
            hash_table->erase_after(prev);
    }
}

bool HashTable::isEmpty() {
    for (int i = 0; i < table_size; i++) {
        if (!hash_table[i].empty())
            return false;
    }

    return true;
}

std::string HashTable::searchTable(int key) {
    int index = hashFunction(key);

    for (auto it = hash_table[index].begin(); it != hash_table[index].end(); it++) {
        if (it->first == key)
            return it->second;
    }
    return "\0";
}

void HashTable::printTable() {
    for (int i = 0; i < table_size; i++) {
        for (auto it = hash_table[i].begin(); it != hash_table[i].end(); it++)
            std::cout << "Key: " << it->first << "\tValue: " << it->second << std::endl;   
    }
    std::cout << std::endl << std::endl;
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