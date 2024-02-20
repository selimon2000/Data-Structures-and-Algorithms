#include <iostream>


int partition(int arr[], int start, int end) {
    // Let's choose Pivot as the last element
    int pivot = arr[end];
    int p_index = start;

    for (int i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            std::swap(arr[p_index], arr[i]);
            p_index++;
        }
    }

    // Place the pivot where it is supposed to be; atm it's at the back
    std::swap(arr[end], arr[p_index]);
    
    return p_index;
}

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int p_index = partition(arr, start, end);
        quickSort(arr, start, p_index - 1);
        quickSort(arr, p_index + 1, end);
    }
}



int main() {
    int my_array[] = {88, 6, 5, 1, 4, 3, 9, 2};
    // int my_array[] = {4, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    // Print array before merging:
    for (int i = 0; i < n; i++)
        std::cout << my_array[i] << ", ";
    std::cout << std::endl;

    quickSort(my_array, 0 , n - 1);

    // Print array afert merging:
    for (int i = 0; i < n; i++)
        std::cout << my_array[i] << ", ";
    std::cout << std::endl;
}