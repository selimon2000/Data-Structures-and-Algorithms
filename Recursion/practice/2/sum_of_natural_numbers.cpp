#include <iostream>

int sumOfNaturalNumbers(int number) {
    if (number == 0)
        return 0;
    
    return sumOfNaturalNumbers(number - 1) + number;
}

int main() {
    std::cout << sumOfNaturalNumbers(10) << std::endl;
}