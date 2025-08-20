#include <bits/stdc++.h>

using namespace std;


// int main() { 
//     // initialising the forward lists 
//     forward_list<int> list1 = { 10, 20, 30, 40 }; 
//     forward_list<int> list2 = { 4, 9 }; 
 
//     // splice_after operation performed 
//     // all elements except the first element in list1 is 
//     // inserted in list 2 between 4 and 9 
//     list2.splice_after( list2.before(), list1, 
//                         list1.before_begin(), list1.end()); 
 
//     cout << "Elements are: " << endl; 
 
//     // loop to print the elements of second list 
//     for (auto it = list2.begin(); it != list2.end(); ++it) 
//         cout << *it << " "; 
// }


int main() {
    forward_list<int> list1 = {10, 20, 30, 40};
    forward_list<int> list2 = {4, 9};

    // splice_after operation performed
    // all elements of list1 are inserted in list2 between 4 and 9
    list1.splice_after(list2.begin(), list1, list1.before_begin(), list1.end());

    // loop to print the elements of second list
    for (auto it = list2.begin(); it != list2.end(); ++it)
        cout << *it << " ";
}