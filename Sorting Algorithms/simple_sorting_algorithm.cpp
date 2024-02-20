// This is a function similar to selection sort, but it doesn't look for the lowest number,
// rather it keeps swapping values if they are smaller. This is inefficient

#include <iostream>

int main() {
    int my_array[] = {88, 6, 5, 1, 4, 3, 9, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (my_array[j] < my_array[i])
                std::swap(my_array[j], my_array[i]);
            
        }
    }

    for(auto number:my_array)
        std::cout << number << ", ";
}