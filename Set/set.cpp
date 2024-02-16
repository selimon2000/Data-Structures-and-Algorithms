#include <iostream>
#include <set>

using namespace std;


int main() {
    
    // To list reverse order
    std::multiset<int, std::greater<int>> s;
    // To list ascending order
    // std::set<int> s;

    s.insert(10);
    s.insert(23);
    s.insert(50);
    s.insert(24);
    s.insert(321);
    s.insert(12);
    s.insert(20);
    
    for (int value : s)
        std::cout << value << ", ";

    std::set<int>::iterator it = s.begin();
    s.erase(it);
    s.erase(24);

    std::cout << std::endl << std::endl;
    for (std::set<int>::iterator it = s.begin(); it != s.end(); it++)
        std::cout << *it << ", ";


/*


// declare array
int out_of_order[] = {2,1,4,3, 5, 4, 4, 4, 4};
   
// create set from array
set<int> set_from_array{begin(out_of_order), end(out_of_order)};
   
// print every element in set
for (auto it=set_from_array.begin(); it!=set_from_array.end(); ++it)
    cout << ' ' << *it;
cout << '\n';
// output: 1 2 3 4 5
*/
}