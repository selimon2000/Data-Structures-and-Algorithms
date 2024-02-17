#include <iostream>
#include <algorithm>


int main() {
    int array[] = {1, 3, 3, 3, 3, 3, 4, 4, 5};
    int size = sizeof(array) / sizeof(array[1]);


    int target = 5;
    if (std::binary_search(array, array + size, target))
        std::cout << "Number:" << target << " does exist" << std::endl;
    else
        std::cout << "Number:" << target << " does not exist" << std::endl;

    target = 4;
    int occurence = std::distance(std::lower_bound(array, array + size, target), std::upper_bound(array, array + size, target));
    std::cout << "Number:" << target << " occurs " << occurence << " times." << std::endl;

    std::cout << *std::lower_bound(array, array + size, 2);
}