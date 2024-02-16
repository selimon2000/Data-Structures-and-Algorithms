#include <iostream>
#include <string>


bool isPalindrome(std::string my_string) {
    if (my_string.size() == 0 || my_string.size() == 1)
        return true;

    if (my_string.front() == my_string.back())
        return isPalindrome(my_string.substr(1, my_string.size() - 2));
    // else (else statement not necessary)
    return false;
}

int main() {
    std::cout << isPalindrome("mdadamimadadm") << std::endl;
    std::cout << isPalindrome("racecar") << std::endl;
    std::cout << isPalindrome("11022011") << std::endl;
}