#include <iostream>


// Selection sort swaps the number with the lowest number it can find (unless the lowest number is already in the right place on the LHS)
void selectionSort(int* my_array, int n) {

    for (int i = 0; i < n - 1; i++) {
        int smallestIndex = i;

        // Function that finds the next biggest number in the whole array
        for (int j = i + 1; j < n; j++) {
            if (my_array[j] < my_array[smallestIndex])
                smallestIndex = j;
        }

        if (smallestIndex != i)        
            std::swap(my_array[smallestIndex], my_array[i]);
    }
}


int main() {
    int my_array[] = {6, 1, 4, 3, 5, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    selectionSort(my_array, n);

    for (auto num:my_array)
        std::cout << num << ", ";    
}