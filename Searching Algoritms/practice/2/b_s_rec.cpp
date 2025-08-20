#include <iostream>
#include <cstdint>
#include <limits>

using namespace std;


template<typename T>
uint16_t binary_search(T *arr, T tar, uint16_t l, uint16_t u) {
    if (l > u) return UINT16_MAX;

    const uint16_t mid = (l + u) / 2;
    const T &mid_val = arr[mid];

    if (abs(mid_val - tar) <= numeric_limits<T>::epsilon() * max(mid_val, tar)) return mid;
    if (tar > mid_val)                                      return binary_search(arr, tar, mid + 1, u);
    /*else*/                                                return binary_search(arr, tar, l, mid - 1);
}


int main() {
    int arr[] = {-423, 1, 2, 4, 5, 45, 76, 99, 1210};
    cout << binary_search(arr, 2, 0, (sizeof(arr) / sizeof(arr[0]))-1) << '\n';
}