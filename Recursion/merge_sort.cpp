#include <iostream>
using namespace std;

void merge(int arr[], int left, int middle, int right, int size)
{
    int i = left;
    int j = middle + 1;
    int k = left;

    int temp[size];

    while (i <= middle && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= middle)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r, int size)
{
    // when !l<r, that means that there is only 1 element remaining
    if (l < r)
    {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, size);
        mergeSort(arr, m + 1, r, size);

        // Merge the sorted subarrays
        merge(arr, l, m, r, size);
    }
}

// Driver program
int main()
{
    int arr[] = {6000, 5, 12, 10, 9, 1, 1, 1, 100, 1002, 76};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "\n\nUnsorted array: \n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    mergeSort(arr, 0, size - 1, size);

    cout << "\n\nSorted array: \n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}