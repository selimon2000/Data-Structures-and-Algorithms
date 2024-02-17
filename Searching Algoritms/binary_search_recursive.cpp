#include <iostream>

bool binarySearchExists(int array[], int target, int start, int end) {
    if (start > end)
        return 0;

    int mid = start + (end - start) / 2;

    if (target == array[mid])
        return true;

    if (target > array[mid])
        return binarySearchExists(array, target, mid + 1, end);
    return binarySearchExists(array, target, start, mid - 1);
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    std::cout << binarySearchExists(array, 6, 0, sizeof(array)/sizeof(array[0]));
}