#include <iostream>


int recursiveFunction(int number)
{
    if (number == 0)
    {
        return 0;
    }

    return number + recursiveFunction(number - 1);
}

int main()
{
    std::cout << recursiveFunction(1);
}