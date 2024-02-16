#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> my_set;
    
    my_set.insert(9);
    my_set.insert(2);
    my_set.insert(3);
    my_set.insert(4);
    my_set.insert(5);
    my_set.insert(6);
    my_set.insert(7);

    my_set.erase(2);

    for (int number : my_set)
        std::cout << number << ", ";
    std::cout << std::endl << std::endl;    
}