#include <forward_list>
#include <iostream>
#include <vector>
#include <array>

using namespace std;


int main() {
    std::forward_list<int> myList;  // Create an empty list
    std::array<int, 5> arr{1, 2, 3, 4, 5};
    myList.assign(arr);
    myList.assign(arr.begin(), arr.end());
    for (auto num : myList) cout << num << '\n';
    
    // // 1. push_back() - Adds element at the end
    // myList.push_back(5);    // List: [5]
    
    // // 2. push_front() - Adds element at the beginning
    // myList.push_front(3);   // List: [3, 5]

    // // 3. insert() - Adds element at a specific position
    // auto it = myList.begin();  // Iterator to first element
    // std::advance(it, 1);       // Move iterator to second position
    // myList.insert(it, 4);      // List: [3, 4, 5]

    // // 4. insert() with multiple copies
    // myList.insert(it, 2, 7);   // Insert two 7s at position
    //                            // List: [3, 7, 7, 4, 5]

    // // 5. insert() with range from another container
    // std::list<int> otherList = {10, 11, 12};
    // myList.insert(it, otherList.begin(), otherList.end());
    //                            // List: [3, 7, 7, 10, 11, 12, 4, 5]
}