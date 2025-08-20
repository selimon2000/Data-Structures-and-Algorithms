#include <iostream>


void selectionSort(int* my_array, int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find min element
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (my_array[j] < my_array[min_index])
                min_index = j;
        }
        if (min_index != i)
            std::swap(my_array[i], my_array[min_index]);       
    }
}


int main() {
    int my_array[] = {6, 1, 4, 3, 5, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    selectionSort(my_array, n);

    for (auto num:my_array)
        std::cout << num << ", ";    
}