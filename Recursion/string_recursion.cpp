#include <iostream>
#include <string>
using namespace std;

 
void reverse(string str)
{
    if(str.size() == 0)
        return;
    
    reverse(str.substr(1));
    std::cout << str[0];
}
 
int main()
{
    std::string a = "Selimon Shukurzad";

    reverse(a);
}