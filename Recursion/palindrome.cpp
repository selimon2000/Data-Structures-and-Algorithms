#include <bits/stdc++.h>
using namespace std;

bool pallindrome_checker(string str)
{
    // cout<<"String is: "<< str<<endl;

    if (str.size() == 0 || str.size() == 1)
    {
        // cout<<"String is: "<< str<<" so it is successful and exiting!"<<endl;
        return true; 
    }

    if (str.front() == str.back())
    {
        return pallindrome_checker(str.substr(1, str.size() - 2));
    }

    else
    {
        return false;
    }
}

int main()
{
    string a = "kayak";
    cout << "Testing if " << a << " is a palindrome: " << pallindrome_checker(a) << endl;

    string b = "11022011";
    cout << "Testing if " << b << " is a palindrome: " << pallindrome_checker(b) << endl;

    string c = "kayakk";
    cout << "Testing if " << c << " is a palindrome: " << pallindrome_checker(c) << endl;
}