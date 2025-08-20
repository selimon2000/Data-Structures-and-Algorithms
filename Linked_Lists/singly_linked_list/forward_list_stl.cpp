#include <iostream>
#include <forward_list>


// int main() {
//     std::forward_list<int> my_list{11, 2, 3, 4, 5};

//     std::cout << "First Element: " << my_list.front();

//     std::cout << "\n\nPrinting List:" << std::endl;
//     for (std::forward_list<int>::iterator it = my_list.begin(); it != my_list.end(); it++)
//         std::cout << *it << ", ";

//     my_list.insert_after(std::next(my_list.before_begin(), 0), 99);

//     std::cout << "\n\nPrinting List:" << std::endl;
//     for (std::forward_list<int>::iterator it = my_list.begin(); it != my_list.end(); it++)
//         std::cout << *it << ", ";

//     // pushing_back
//     auto it = my_list.begin();
//     for (; std::next(it) != my_list.end(); it++);
//     my_list.insert_after(it, 1111);

//     std::cout << "\n\nPrinting List:" << std::endl;
//     for (std::forward_list<int>::iterator it = my_list.begin(); it != my_list.end(); it++)
//         std::cout << *it << ", ";

//     std::cout << "\n\nPrinting List with Range-Based For-Loop:" << std::endl;
//     for (auto node : my_list)
//         std::cout << node << ", ";
//     std::cout << std::endl;
// }



/*
int main() {
    std::forward_list<int> list1 = {1, 2, 3};
    std::forward_list<int> list2 = {4, 5, 6, 7, 8};

    list1.splice_after(list1.before_begin(), list2, list2.begin(), std::next(list2.begin(), 3));

    // Displaying the elements in the modified lists
    std::cout << "List1: ";
    for (const auto& element : list1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "List2: ";
    for (const auto& element : list2) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/



// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     list<int> l1 = {1, 2, 5};
//     list<int> l2 = {4, 3};

//     // Put entire list l2 at start of l1
//     l1.splice(next(l1.begin()), l2);

//     for (auto i : l1) cout << i << " ";
//     cout << "\n\n";

//     // for (auto i : l2) cout << i << " ";
// }


#include <bits/stdc++.h>

using namespace std;


// int main() {
//     list<int> l = {1, 5, 8, 4, 6};

//     // Transfer element 4 and 6 at the beginning
//     l.splice(l.begin(), l, next(l.begin(), 3), l.end());

//     for (auto i : l) cout << i << " ";
// }


int main() {
    list<int> l1 = {1, 5, 8};
    list<int> l2 = {4, 6};

    // Transfer range of elements from l2 to l1
    l1.splice(l1.begin(), l2, l2.begin(), l2.end());

    for (auto i : l1) cout << i << " ";
}