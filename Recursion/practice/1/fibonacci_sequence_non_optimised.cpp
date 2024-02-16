#include <iostream>


int fibonacci(int num)
{
    if (num == 0 || num == 1)
    {
        return num;
    }

    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main()
{
    std::cout << (fibonacci(5));
}