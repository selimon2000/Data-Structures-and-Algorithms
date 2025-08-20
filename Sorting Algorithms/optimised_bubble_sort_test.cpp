#include <iostream>
#include <utility>

using namespace std;


// Even better optimisation: Reduces unnecessary comparisons by limiting the inner loop to the last swap position (n = lastSwapped)
void bubbleSort(int* v, int n) {
    int bound = n;  // Use a separate variable to track the boundary
    int lastSwapped;

    do {
        lastSwapped = 0;
        for (int j = 0; j < bound - 1; ++j) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                lastSwapped = j + 1;
            }
        }
        bound = lastSwapped;  // Update the boundary instead of modifying n
    } while (lastSwapped != 0);
}


int main() {
    int my_array[] = {88, 6, 5, 1, 4, 3, 9, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    bubbleSort(my_array, n);

    for (int i = 0; i < sizeof(my_array) / sizeof(my_array[0]); i++)
        std::cout << my_array[i] << ", ";
    std::cout << std::endl;
}