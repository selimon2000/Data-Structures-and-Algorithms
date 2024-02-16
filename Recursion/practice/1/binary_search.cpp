#include <iostream>


int binary_search(int array[], int target, int left, int right)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (array[mid] == target)
        return mid;

    if (target > array[mid])
        return binary_search(array, target, mid + 1, right);

    return binary_search(array, target, left, mid - 1);
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int target = 9;
    std::cout << binary_search(array, target, 0, sizeof(array) / sizeof(array[0]));

    return 0;
}