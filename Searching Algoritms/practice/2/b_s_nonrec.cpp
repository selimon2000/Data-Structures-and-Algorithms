// #include <iostream>
// #include <cstdint>
// #include <limits>

// using namespace std;


// template <typename T> // array, target, lower, upper
// uint16_t binary_search (T *arr, T tar, uint16_t l, uint16_t u) {

//     while (!(l > u)) {
//         const uint16_t mid = l + (u - l) / 2;
//         const T mid_val = arr[mid];

//         if(abs(mid_val - tar) <= numeric_limits<T>::epsilon())  return mid;
//         if(tar > mid_val)   l = mid + 1;
//         else                u = mid - 1;
//     }


//     return UINT16_MAX;
// }


// int main() {
//     int arr[] = {-423, 1, 2, 4, 5, 45, 76, 99, 1210};
//     cout << binary_search(arr, 2, 0, (sizeof(arr) / sizeof(arr[0]))-1) << '\n';
// }













#include <iostream>
#include <cstdint>
#include <limits>
#include <cmath>

using namespace std;


template <typename T> // array, target, lower, upper
uint16_t binary_search(T *arr, T tar, uint16_t l, uint16_t u) {
    while (l <= u) { // Replace !(l > u) with l <= u for clarity
        const uint16_t mid = l + (u - l) / 2;
        const T mid_val = arr[mid];

        if constexpr (std::is_floating_point_v<T>) {
            // Use epsilon for floating-point types
            if (abs(mid_val - tar) < numeric_limits<T>::epsilon()) return mid;
        } else {
            // Use direct equality for integer types
            if (mid_val == tar) return mid;
        }

        if (tar > mid_val)
            l = mid + 1;
        else
            u = mid - 1;
    }

    return UINT16_MAX; // Return UINT16_MAX if target is not found
}


int main() {
    int arr[] = {-423, 1, 2, 4, 5, 45, 76, 99, 1210};
    cout << binary_search(arr, 2, 0, (sizeof(arr) / sizeof(arr[0])) - 1) << '\n';
    constexpr int x{12};
    static_assert(x==12);

    double arr2[] = {-423.5, 1.0, 2.0, 4.5, 5.0, 45.0, 76.1, 99.99, 1210.2};
    cout << binary_search(arr2, 4.5, 0, (sizeof(arr2) / sizeof(arr2[0])) - 1) << '\n';
}