#include <iostream>


int binarySearchExists(int* array, int target, int start, int end) {
    int mid = start + (start - end) / 2;
    if (array[mid] == target)
        return true;
    if (target > array[mid])
        return binarySearchExists(array, target, mid + 1, end);
    return binarySearchExists(array, target, start, mid - 1);   
}


int main() {
    int array[] = {1, 2, 3, 4, 5};
    std::cout << binarySearchExists(array, 5, 0, sizeof(array)/sizeof(array[0])) << std::endl;
}