#include <iostream>


void bubbleSort(int* my_array, int n) {
    bool isSortedFlag = true;

    for (;n > 0; n--) {
        for (int i = 0; i < n - 1; i++) {

            if (my_array[i] > my_array[i + 1]) {
                std::swap(my_array[i], my_array[i + 1]);
                isSortedFlag = false;
            }
        }
        if (isSortedFlag == true) break;
    }
}


int main() {
    int my_array[] = {88, 6, 5, 1, 4, 3, 9, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    bubbleSort(my_array, n);

    for (int i = 0; i < sizeof(my_array) / sizeof(my_array[0]); i++)
        std::cout << my_array[i] << ", ";
    std::cout << std::endl;
}