#include <iostream>

// Unoptimised
// void bubbleSort(int* my_array, int n) {
//    for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++)
//             if (my_array[i] > my_array[j])
//                 std::swap(my_array[i], my_array[j]);
//    }
// }

void bubbleSort(int* my_array, int n) {
   for (int iteration = 0; iteration < n - 1; iteration++) {

        for (int i = 0; i < (n - iteration - 1); i++)
            if (my_array[i] > my_array[i + 1])
                std::swap(my_array[i], my_array[i + 1]);
   }
}

void bubbleSort(int *my_array, int n) {
    for (int iteration = 0; iteration < n - 1; iteration++) {
        
        // No swapping means array has already been sorted
        bool swapped = false;
        for (int i = 0; i < (n - iteration - 1); i++) {
            if (my_array[i] > my_array[i + 1]) {
                std::swap(my_array[i], my_array[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    int my_array[] = {6, 1, 4, 3, 5, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    bubbleSort(my_array, n);

    for (auto num : my_array)
        std::cout << num << ", ";
}