#include <iostream>
#include <cstring>

void merge(int *array, int l, int m, int r) {   
    int n = r - l + 1;
    int sorted[n];

    int left = l, right = m + 1, index = 0;
    for (; left <= m && right <= r; index++) {
        if (array[left] < array[right]) {
            sorted[index] = array[left];
            left++;
        }
        else {
            sorted[index] = array[right];
            right++;
        }
    }

    if (left <= m)          memcpy(&sorted[index], &array[left], (m - left + 1) * sizeof(int));
    else if (right <= r)    memcpy(&sorted[index], &array[right], (r - right + 1) * sizeof(int));

    std::memcpy(&array[l], sorted, n * sizeof(int));
}

void mergeSort(int *array, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        merge(array, l, m, r);
    }
}

int main() {
    int my_array[] = {6, 1, 88, 4, 3, 5, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    mergeSort(my_array, 0, n - 1);

    for (auto num : my_array)
        std::cout << num << ", ";
}