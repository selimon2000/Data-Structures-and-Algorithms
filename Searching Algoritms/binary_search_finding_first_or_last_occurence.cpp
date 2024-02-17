#include <iostream>


// int binarySearchFirstOccurance(int array[], int target, int size) {
//     int start = 0, end = size - 1;
//     int result = -1;

//     while (start <= end) {
//         int mid = start + (end - start) / 2;

//         if (target == array[mid]) {
//             result = mid;
//             end = mid - 1;
//         }
//         else if (target > array[mid])
//             start = mid + 1;
//         else if (target < array[mid])
//             end = mid - 1;
//     }

//     return result;
// }

// int binarySearchLastOccurance(int array[], int target, int size) {
//     int start = 0, end = size - 1;
//     int result = -1;

//     while (start <= end) {
//         int mid = start + (end - start) / 2;

//         if (target == array[mid]) {
//             result = mid;
//             start = mid + 1;
//         }
//         else if (target > array[mid])
//             start = mid + 1;
//         else if (target < array[mid])
//             end = mid - 1;
//     }

//     return result;
// }


// int main() {
//     int array[] = {1, 2, 3, 3, 3, 3, 3, 4, 4, 5};
//     std::cout << binarySearchFirstOccurance(array, 3, sizeof(array)/sizeof(array[0])) << std::endl;
//     std::cout << binarySearchLastOccurance(array, 3, sizeof(array)/sizeof(array[0])) << std::endl;
// }



int binarySearchOccurance(int array[], int target, int size, bool searchLeft) {
    int start = 0, end = size - 1;
    int result = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (target == array[mid]) {
            result = mid;
            if (searchLeft)            
                end = mid - 1;
            else
                start = mid + 1;
        }
        else if (target > array[mid])
            start = mid + 1;
        else if (target < array[mid])
            end = mid - 1;
    }

    return result;
}


int main() {
    int array[] = {1, 2, 3, 3, 3, 3, 3, 4, 4, 5};
    std::cout << binarySearchOccurance(array, 3, sizeof(array)/sizeof(array[0]), true) << std::endl;
    std::cout << binarySearchOccurance(array, 3, sizeof(array)/sizeof(array[0]), false) << std::endl << std::endl;

    // Find the difference
    int left = binarySearchOccurance(array, 3, sizeof(array)/sizeof(array[0]), true);
    if (left == -1)
        std::cout << "Number of occurences is: 0" << std::endl;
    else
        std::cout << "Number of occurences is: " << binarySearchOccurance(array, 3, sizeof(array)/sizeof(array[0]), false) - left + 1 << std::endl << std::endl;
}