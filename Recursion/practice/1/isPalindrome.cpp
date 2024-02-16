#include <iostream>
#include <string>

void isPalindrome(std::string x)
{
    if (x.length() == 0 || x.length() == 1)
    {
        std::cout << "It is a palindrome";
        return;
    }

    if (x.front() != x.back())
    {
        std::cout << "Front: " << x.front() << ", Back: " << x.back() << std::endl;
        std::cout << "It is not a palindrome";
        return;
    }

    isPalindrome(x.substr(1, x.length() - 2));
}

int main()
{
    std::string x = "madamimadam";
    isPalindrome(x);

    return 0;
}