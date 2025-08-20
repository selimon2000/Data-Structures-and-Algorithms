#include <iostream>


void bubbleSort(int* my_array, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool isSorted = true;

        for (int j = i + 1; j < n; j++) {
            if (my_array[i] > my_array[j]) {
                std::swap(my_array[i], my_array[j]);
                isSorted = false;
            }
        }

        if (isSorted)
            return;
    }
}


int main() {
    int my_array[] = {6, 1, 4, 3, 5, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    bubbleSort(my_array, n);

    for (auto num:my_array)
        std::cout << num << ", ";    
}