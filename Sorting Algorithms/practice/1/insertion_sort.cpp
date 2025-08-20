#include <iostream>


// Distinction is that elements are shifted, rather than swapped. e.g. array[i] = array[i-1]
// This creates efficiency
void insertionSort(int* my_array, int n) {

    for (int i = 1; i < n; i++) {
        int value = my_array[i];

        int j = i;
        for (; j > 0 && value < my_array[j - 1]; j--)
            my_array[j] = my_array[j - 1];
        
        my_array[j] = value;
    }
    
}

int main() {
    // int my_array[] = {6, 1, 4, 3, 5, 2};
    int my_array[] = {88, 6, 5, 1, 4, 3, 9, 2};

    int n = sizeof(my_array) / sizeof(my_array[0]);

    insertionSort(my_array, n);

    for (auto num : my_array)
        std::cout << num << ", ";    
}