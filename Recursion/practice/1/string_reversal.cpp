#include <iostream>
#include <string>

void reverseString(std::string x)
{
    if (x.length() == 0)
    {
        return;
    }

    reverseString(x.substr(1));
    std::cout << x.at(0);
}

int main()
{
    std::string x = "Hello";
    reverseString(x);

}