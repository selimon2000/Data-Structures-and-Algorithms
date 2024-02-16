#include <iostream>
#include <string>


void printStringReverse(std::string my_string) {
    if (my_string.size() == 0)
        return;
    
    printStringReverse(my_string.substr(1));
    std::cout << my_string[0];
}


int main() {
    std::string my_name = "Selimon  Shukurzad";
    printStringReverse(my_name);
}