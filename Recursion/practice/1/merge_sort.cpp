#include <iostream>
#include <string.h>

void sort(int array[], int start, int end)
{
    int size_of_array = end - start + 1;
    int mid = ((start + end) / 2) + 1;

    int temp_array[size_of_array];

    // i is left array, j is right array
    int i = start, j = mid, k = 0; // Adjust positions based on start index

    while (i <= mid - 1 && j <= end)
    {
        if (array[i] <= array[j])
            temp_array[k++] = array[i++];
        else
            temp_array[k++] = array[j++];
    }

    while (i <= mid - 1)
        temp_array[k++] = array[i++];
    while (j <= end)
        temp_array[k++] = array[j++];

    // for (size_t i = start; i <= end; i++)
    //     array[i] = temp_array[i - start]; // reason we are minusing is because temp_array isn't always as big as the main array, sometimes it is just a portion
    memcpy(&array[start], &temp_array, size_of_array * sizeof(int));


    return;
}

void mergeSort(int array[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        sort(array, start, end);
    }
    return;
}

int main()
{
    int array[6] = {1, 5, 4, 3, 2, 1};

    mergeSort(array, 0, sizeof(array) / sizeof(array[0]) - 1);

    for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++)
        std::cout << array[i] << " ";

    return 0;
}