// This is my implementation of Binary_Search_Tree after learning this a year ago and just trying to remember how it works
// This works but it is not the best implementation


#include <iostream>


bool numberExistsUnwrapped(int my_array[], int target, int size, int pos) {
    if (my_array[pos] == target)
        return true;
    // It is important that we check that the position at the array is the target, before we execute the line below
    // This is because pos == 0 is VALID. Just like pos == (size - 1) is VALID
    if (pos <= 0 || pos >= (size - 1))
        return false;

    if (target > my_array[pos])
        return numberExistsUnwrapped(my_array, target, size, (pos + ((size - pos) / 2)));
    if (target < my_array[pos])
        return numberExistsUnwrapped(my_array, target, size, pos / 2);
    
    // This statement is to get rid of warning:
    return false;
}

bool numberExists(int my_array[], int target, int size) {
    int pos = size / 2;
    return numberExistsUnwrapped(my_array, target, size, pos);
}


int main() {
    // int my_array[] = {1, 2, 3, 4, 5};
    int my_array[] = {0, 1, 2};

    std::cout << numberExists(my_array, 0, sizeof(my_array) / sizeof(my_array[0]));
}