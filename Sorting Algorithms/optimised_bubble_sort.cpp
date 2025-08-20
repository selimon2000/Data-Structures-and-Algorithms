#include <iostream>
#include <utility>

using namespace std;


void bubbleSort(int* v, int n) {

    for (int i = 0; i < n - 1; i++) {

        // Creating a flag to denote the case wwhen array is sorted and doesnt cause any swap
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);              
                flag = true;
            }
        }
        if (!flag) break;
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