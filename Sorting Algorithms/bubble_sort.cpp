#include <iostream>


int main() {
    int my_array[] = {88, 6, 5, 1, 4, 3, 9, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);
    bool isSortedFlag = true;

    while (n > 0) {
        for (int i = 0; i < n - 1; i++) {

            if (my_array[i] > my_array[i + 1]) {
                std::swap(my_array[i], my_array[i + 1]);
                if (isSortedFlag == true) isSortedFlag = false;
            }
        }
        if (isSortedFlag == true) break;
        
        n--;
    }
    
    for (int i = 0; i < sizeof(my_array) / sizeof(my_array[0]); i++)
        std::cout << my_array[i] << ", ";
    
}