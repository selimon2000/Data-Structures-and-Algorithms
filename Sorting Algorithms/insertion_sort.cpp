#include <iostream>


int main() {
    int my_array[] = {88, 6, 5, 1, 4, 3, 9, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    for (int i = 1; i < n; i++) {
        int value = my_array[i];
        
        // Move it if it is finds elements to its left that are greater than it
        int j = i;
        // Essential for j > 0 so that it doesn't go to -1
        for (; j > 0 && my_array[j - 1] > value; j--)
            my_array[j] = my_array[j - 1];
        
        my_array[j] = value;
    }

    for (int i = 0; i < n; i++)
        std::cout << my_array[i] << ", ";    
}