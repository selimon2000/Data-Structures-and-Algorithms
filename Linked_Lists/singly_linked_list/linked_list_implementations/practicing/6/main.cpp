#include "linked_list.h"
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int main() {
    linked_list<int> my_list;

    // Test case 1: Add elements using push_back
    cout << "Test Case 1: Adding elements using push_back\n";
    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);
    my_list.printList(); // Expected output: 1, 2, 3.

    // Test case 2: Add elements using push_front
    cout << "\nTest Case 2: Adding elements using push_front\n";
    my_list.push_front(0);
    my_list.printList(); // Expected output: 0, 1, 2, 3.

    // // Test case 3: Insert element at a specific position
    // cout << "\nTest Case 3: Inserting element at position 2\n";
    // my_list.insert(2, 99);
    // my_list.printList(); // Expected output: 0, 1, 99, 2, 3.

    // // Test case 4: Remove the first element
    // cout << "\nTest Case 4: Removing the first element\n";
    // my_list.popFront();
    // my_list.printList(); // Expected output: 1, 99, 2, 3.

    // // Test case 5: Remove the last element
    // cout << "\nTest Case 5: Removing the last element\n";
    // my_list.popBack();
    // my_list.printList(); // Expected output: 1, 99, 2.

    // // Test case 6: Size of the list
    // cout << "\nTest Case 6: Checking size of the list\n";
    // cout << "Size: " << my_list.size() << endl; // Expected output: Size: 3.

    // // Test case 7: Print reverse list
    // cout << "\nTest Case 7: Printing reverse list\n";
    // my_list.printReverseList(); // Expected output: 2, 99, 1.

    // // Test case 8: Print list recursively
    // cout << "\nTest Case 8: Printing list recursively\n";
    // my_list.printListRecursive(); // Expected output: 1, 99, 2.
    // cout << '\n';

    // // Test case 9: Reverse the list
    // cout << "\nTest Case 9: Reversing the list\n";
    // my_list.reverseList();
    // my_list.printList(); // Expected output: 2, 99, 1.

    // // Test case 10: Edge case - Insert at invalid position
    // cout << "\nTest Case 10: Inserting at an invalid position\n";
    // if (!my_list.insert(100, 42)) {
    //     cout << "Insertion failed as expected.\n";
    // }

    // my_list.printList(); // Expected output: 2, 99, 1.


    // linked_list<string> my_list;
    // my_list.push_back("Selimon"s);
    // my_list.push_back("Shukurzad"s);
    // my_list.push_back("is"s);
    // my_list.push_back("the"s);
    // my_list.push_back("best"s);
    // my_list.printList();

    // linked_list<uint16_t> my_list;
    // my_list.push_back(67);
    // my_list.push_back(69);
    // my_list.push_back(72);
    // my_list.push_back(75);
    // my_list.push_back(97);

    // my_list.printList();

    // cout << "Hello World\n";
}