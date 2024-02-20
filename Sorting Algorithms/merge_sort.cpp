#include <iostream>
#include <cstring>


void merge(int arr[], int l, int m, int r) {
    //  There are 2 sorted arrays:
    //  l_array: l to m
    //  r_array: m+1 to r
    //  k is the index of the array where the elements will 'land'
    int l_n = m - l + 1;
    int l_array[l_n];
    std::memcpy(l_array, &arr[l], l_n * sizeof(int));
    int r_n = r - m;
    int r_array[r_n];
    std::memcpy(r_array, &arr[m+1], r_n * sizeof(int));

    int i = 0;
    int j = 0;
    int k = l;
    for (; i < l_n && j < r_n; k++) {
        if (l_array[i] <= r_array[j]) {
            arr[k] = l_array[i];
            i++;
        }
        else {
            arr[k] = r_array[j];
            j++;
        }
    }

    // If one of the arrays is finished, the other one will not be finished
    // Only 1 of these for loops function will run
    for (; i < l_n; arr[k] = l_array[i], i++, k++);
    for (; j < r_n; arr[k] = r_array[j], j++, k++);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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

    mergeSort(my_array, 0 , n - 1);

    // Print array afert merging:
    for (int i = 0; i < n; i++)
        std::cout << my_array[i] << ", ";
    std::cout << std::endl;
}