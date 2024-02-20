#include <iostream>
#include <algorithm>

int main() {
    int my_array[] = {88, 6, 5, 1, 4, 3, 9, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    // Print array before merging:
    for (int i = 0; i < n; i++)
        std::cout << my_array[i] << ", ";
    std::cout << std::endl;

    std::sort(my_array, my_array + n);

    // Print array afert merging:
    for (int i = 0; i < n; i++)
        std::cout << my_array[i] << ", ";
    std::cout << std::endl;
}