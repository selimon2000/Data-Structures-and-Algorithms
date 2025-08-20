#include <iostream>
#include <algorithm>

int main() {
    int my_array[] = {6, 1, 4, 3, 5, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    std::sort(my_array, &my_array[n]);

    for (auto num:my_array)
        std::cout << num << ", ";    
}