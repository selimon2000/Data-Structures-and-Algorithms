#include <iostream>


void insertionSort(int* my_array, int n) {
    if (n<2) return;
    
    for (int i = 1; i < n; i++) {

        int value = my_array[i];

        int j = i;
        for (; j > 0 && my_array[j - 1] > value; j--) 
            my_array[j] = my_array[j - 1];
        
        my_array[j] = value; 
    }
    
}


int main() {
    int my_array[] = {6, 1, 4, 3, 5, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    insertionSort(my_array, n);

    for (auto num : my_array)
        std::cout << num << ", ";
}