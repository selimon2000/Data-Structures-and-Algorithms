#include <vector>
#include <string>
#include <iostream>


int main() {
    std::vector<std::string> vec;
    std::cout << typeid(vec).get_name() << std::endl;
}