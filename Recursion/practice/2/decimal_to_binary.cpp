#include <iostream>


void decimalToBinary(int number) {
    if (number == 0)
        return;
    
    std::cout << number % 2 << ", ";
    decimalToBinary(number/2);
}

int main() {
    decimalToBinary(5);
}