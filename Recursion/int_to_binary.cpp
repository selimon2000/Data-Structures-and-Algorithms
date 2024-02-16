#include <bits/stdc++.h>
using namespace std;


void decimalToBinary(int number)
{
    if (number == 0)
    {
        return;
    }

    else
    {
        decimalToBinary(number / 2);
        cout << number % 2;
    }
}


int main()
{
    double a = 23;
    // a=100;
    cout << "Converting decimal: " << a << " into a binary number:";
    // printf("Hello\n");
    decimalToBinary(a);
    a=11;
    
    double b = 00255;
    cout << "\n\nConverting decimal: " << b << " into a binary number: ";
    decimalToBinary(b);

    double c = 2.5;
    cout << "\n\nConverting decimal: " << c << " into a binary number: ";
    decimalToBinary(c);
}