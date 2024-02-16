#include <iostream>

// void convertToBinary(int x)
// {
//     if (x < 2)
//     {
//         std::cout << x % 2;
//         return;
//     }

//     convertToBinary(x / 2);
//     std::cout << x % 2;
//     return;
// }

void convertToBinary(int x)
{
    if (x == 0)
        return;

    convertToBinary(x / 2);
    std::cout << x % 2;
    return;
}

int main()
{
    int x = 23;
    convertToBinary(x);
}