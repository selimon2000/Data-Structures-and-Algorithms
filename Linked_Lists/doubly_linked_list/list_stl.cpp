#include <iostream>
#include <list>

/*
int main() {
    std::list<int> my_list = {1, 2, 3, 4};
    my_list.push_front(1);
    my_list.push_back(5);        

    // Remove method:deletes all instance of the value which is input; if there are multiple values it deletes all values
    my_list.remove(1);
    for (std::list<int>::iterator it = my_list.begin(); it != my_list.end(); it++)
        std::cout << *it << ", ";
    std::cout << std::endl;

    // Printing First & Last elements of list
    std::cout<< "First Element: " << my_list.front() << std::endl;
    std::cout<< "Last Element: " << my_list.back() << std::endl;
    // Printing size of list
    std::cout<< "Size: "<< my_list.size() << std::endl;
    std::cout << std::endl;
   

    // Printing list using Range Based For Loaop
    for (int number : my_list)
        std::cout << number << ", ";
    std::cout << std::endl << std::endl;
    

    // Printing List with Iterator ////////////////
    for (std::list<int>::iterator it = my_list.begin(); it != my_list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;


    // Printing List with Iterator using Auto //////
    for (auto it = my_list.begin(); it != my_list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;


    // Printing backwards: Old Skool //////////////////
    std::cout << "Printing backwards: Old Skool" << std::endl;
    auto it = my_list.end();
    it--;
    for (; it != my_list.begin(); --it) {
        std::cout << *it << " ";
    }
    std::cout << *it << " ";
    std::cout << std::endl << std::endl;
    

    // Printing backwards //////////////////
    for (std::list<int>::reverse_iterator it = my_list.rbegin(); it != my_list.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

    for (auto it = my_list.rbegin(); it != my_list.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;


    // Erasing Elements ////////////
    my_list.erase(my_list.begin());
    my_list.erase(my_list.begin());

    std::cout << "Printing List after deleting the first 2 elements:" << std::endl;
    for (int number : my_list) {
        std::cout << number << ", ";
    }


    // Print middle of list
    std::list<int>::iterator my_interator = my_list.begin();
    my_interator--;
    std::advance(my_interator, my_list.size()/2);
    std::cout << "\nMiddle Number: " << *my_interator << std::endl;


    // Print middle of list but use reverse iterator so I don't have to '--' intiially
    std::list<int>::reverse_iterator r_interator = my_list.rend();
    std::advance(r_interator, (my_list.size()/2) * -1);
    std::cout << "Middle Number: " << *r_interator << std::endl << std::endl;

    // Reverse List with container method
    std::cout << "Printing list after reversing:" << std::endl;
    my_list.reverse();
    for (std::list<int>::iterator it = my_list.begin(); it != my_list.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    // Sorting list - this won't have any difference on my list as it is already sorted
    my_list.sort();

    // Max size?
    std::cout << "Max Size: " << my_list.max_size() << std::endl << std::endl;

    // Clearing a list
    my_list.clear();
    std::cout << "Size of list after clearing: " << my_list.size() << std::endl;    
}
*/

// Insert Operation
/*
int main() {
    // Creating a list of integers
    std::list<int> myList;

    // Adding elements to the list using push_back
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    // Displaying the initial elements in the list
    std::cout << "Initial list elements: ";
    for (auto element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Using insert to add an element at a specific position
    // Inserting the value 15 before the second element (20)
    auto it = std::next(myList.begin(), 0);  // Iterator pointing to the second element
    myList.insert(it, 15);

    // Displaying the elements in the list after insertion
    std::cout << "List elements after insertion: ";
    for (auto element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
*/

// Merge Operation
/*
int main() {
    std::list<int> list_1{0, 20, 90, 91, 93};
    std::list<int> list_2{0, 21, 2, 8};

    std::cout << "Printing List 1: " << std::endl;
    for (int node : list_1)
        std::cout << node << ", ";

    std::cout << std::endl;

    std::cout << "Printing List 2: " << std::endl;
    for (int node : list_2)
        std::cout << node << ", ";
    
    std::cout << std::endl;
    std::cout << std::endl;


    list_1.merge(list_2);
    std::cout << "After Merging: " << std::endl << std::endl;


    std::cout << "Printing List 1: " << std::endl;
    for (int node : list_1) {
        std::cout << node << ", ";
    }
    std::cout << std::endl;

    std::cout << "Printing List 2: " << std::endl;
    for (int node : list_2) {
        std::cout << node << ", ";
    }
}
*/


// Splice Operation
/*
int main() {
    std::list<int> list_1{0, 20, 90, 91, 93};
    std::list<int> list_2{9, 21, 2, 8};

    std::cout << "Printing List 1: " << std::endl;
    for (int node : list_1) {
        std::cout << node << ", ";
    }
    std::cout << std::endl;

    std::cout << "Printing List 2: " << std::endl;
    for (int node : list_2) {
        std::cout << node << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    list_1.splice(next(list_1.begin(), 2), list_2);
    std::cout << "After Slicing: " << std::endl << std::endl;


    std::cout << "Printing List 1: " << std::endl;
    for (int node : list_1)
        std::cout << node << ", ";
    
    std::cout << std::endl;

    std::cout << "Printing List 2: " << std::endl;
    for (int node : list_2)
        std::cout << node << ", ";
}
*/

/*
int main() {
    std::list<int> x(5,4);
    x.resize(7, 99);

    for (int node : x)
        std::cout << node << ", ";
    
}
*/

/*
int main() {
    std::list<int> sourceList = {1, 2, 3, 4, 5};
    std::list<int> destinationList{6, 7, 8, 9, 10, 12};

    // Using std::copy to copy elements from sourceList to destinationList
    std::copy(sourceList.begin(), sourceList.end(), destinationList.begin());

    // Displaying the elements in the destinationList
    for (const auto& element : destinationList)
        std::cout << element << " ";
    
    std::cout << std::endl;
}
*/

// /*
int main() {
    std::list<int> sourceList = {1, 2, 3, 4, 5};
    std::list<int> destinationList{6, 7, 8, 9};

    // Using std::copy to copy elements from sourceList to destinationList
    std::copy(sourceList.begin(), sourceList.end(), std::back_inserter(destinationList));

    // Displaying the elements in the destinationList
    for (int element : destinationList)
        std::cout << element << " ";
    std::cout << std::endl;
}
// */

// Very good 
/*
int main() {
    std::list<int> sourceList = {7, 8, 9};
    std::list<int> destinationList = {1, 2, 3, 4, 5, 6};

    // Find the insertion position in the middle of destinationList
    auto insertionPosition = destinationList.begin();
    std::advance(insertionPosition, 3);  // Insert at the fourth position

    // Use std::copy to insert elements from sourceList into destinationList
    std::copy(sourceList.begin(), sourceList.end(), std::inserter(destinationList, insertionPosition));

    for (int number:destinationList)
        std::cout << number << ", ";
}
*/


//     // Displaying the elements in the sourceList
//     std::cout << "Source List: " << std::endl;
//     for (int element : sourceList) {
//         std::cout << element << " ";
//     }
//     std::cout << std::endl << std::endl;

//     // Displaying the elements in the modified destinationList
//     std::cout << "Destination List: " << std::endl;
//     for (int element : destinationList) {
//         std::cout << element << " ";
//     }
//     std::cout << std::endl;
// }

/*
#include <iterator> 
#include <deque> 
#include <algorithm> 
using namespace std; 
int main() 
{ 
    // Declaring first container 
    deque<int> v1 = { 1, 2, 3 }; 
  
    // Declaring second container for 
    // copying values 
    deque<int> v2 = { 4, 5, 6 }; 
  
    deque<int>::iterator i1; 
    i1 = v2.begin() + 1; 
    // i1 points to next element of 4 in v2 
  
    // Using std::inserter inside std::copy 
    std::copy(v1.begin(), v1.end(), std::inserter(v2, i1)); 
    // v2 now contains 4 1 2 3 5 6 
  
    // Displaying v1 and v2 
    cout << "v1 = "; 
  
    int i; 
    for (i = 0; i < 3; ++i) { 
        cout << v1[i] << " "; 
    } 
  
    cout << "\nv2 = "; 
    for (i = 0; i < 6; ++i) { 
        cout << v2[i] << " "; 
    } 
  
    return 0; 
} 



// Same as above but less lines
/*
int main() {
    std::list<int> sourceList = {7, 8, 9};
    std::list<int> destinationList = {1, 2, 3, 4, 5, 6};

    std::copy(sourceList.begin(), sourceList.end(), std::inserter(destinationList, std::next(destinationList.begin(), 3)));

    // Displaying the elements in the modified destinationList
    for (const auto& element : destinationList)
        std::cout << element << " ";
    
    std::cout << std::endl;
}
*/

/*
int main() {
    std::list<int> sourceList = {7, 8, 9};
    std::list<int> destinationList = {1, 2, 3, 4, 5, 6};

    std::copy(sourceList.begin(), sourceList.end(), destinationList.begin());

    for (const auto& element : destinationList)
        std::cout << element << " ";
    
    std::cout << std::endl;
}
*/