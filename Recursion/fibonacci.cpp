#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> fibonacci_vector;

int fib(int x)
{
    // cout << "X is: " << x << ", Size of Vector is: " << fibonacci_vector.size();
    // Search vector rather than calculating IF it is already there
    if (fibonacci_vector.size() > x)
    {
        // cout << "Here" << endl;
        return fibonacci_vector.at(x);
    }

    else if ((x == 1) || (x == 0))
    {
        fibonacci_vector.push_back(x);
        return (x);
    }
    else
    {
        int result = fib(x - 1) + fib(x - 2);
        fibonacci_vector.push_back(result);
        return result;
    }
}

int main()
{
    cout << "\n\nEnter the number of terms of series : ";

    int x;
    cin >> x;

    cout << "\nFibonnaci Series : ";

    int i = 0;
    while (i < x)
    {
        cout << " " << fib(i);
        i++;
    }
}