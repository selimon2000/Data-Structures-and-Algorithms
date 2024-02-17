#include <iostream>


bool binarySearchExists(int array[], int target, int size) {
    int start = 0, end = size - 1;

    while (start <= end) {
        // The line below has been replaced, as the low+high may overflow,
        // if the number is too high because it has to temporarily store (high + low)
        // int mid = (start + end) / 2;
        int mid = start + (end - start)/2;

        if (target == array[mid])
            return true;
        else if (target > array[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return false;
}


int main() {
    int array[] = {1, 2, 3, 4, 5};
    std::cout << binarySearchExists(array, 1, sizeof(array)/sizeof(array[0]));
}