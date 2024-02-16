#include <iostream>
#include <deque>
#include <vector>

int main() {
    std::deque<int> my_deque(9,1);

    std::cout << sizeof(my_deque) << std::endl << std::endl;

    my_deque.push_back(313);

    for (std::deque<int>::iterator it = my_deque.begin(); it != my_deque.end(); it++)
        std::cout << *it << ", ";
    std::cout << std::endl << std::endl;

    for (int number:my_deque)
        std::cout << number << ", ";
    std::cout << std::endl << std::endl;
}