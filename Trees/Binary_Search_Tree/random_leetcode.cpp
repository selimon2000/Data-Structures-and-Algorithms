#include <array>
#include <iostream>

using namespace std;


template <size_t N>
array<int, 2> get2NonRepeatingNos(array<int, N>& nums) {
    // Pass 1: Get the XOR of the two numbers we need to find
    long long int diff = 0;
    for (const auto &i : nums) diff = i ^ diff;

    // Get its last set bit
    diff &= -diff;

    // Pass 2: Go through all numbers again, but separated into 2 lists
    array<int, 2> rets{0}; // this array stores the two numbers we will return

    for (const int &num : nums) {
        // the bit is not set   
        if ((num & diff) == 0)  rets[0] ^= num;
        // the bit is set
        else                    rets[1] ^= num;
    }

    // Ensure the order of the returned numbers is consistent
    if (rets[0] > rets[1]) swap(rets[0], rets[1]);


    return rets;
}


int main() {
    array<int, 8> arr = { 2, 3, 7, 9, 11, 2, 3, 11 };

    array<int, 2> result = get2NonRepeatingNos(arr);
    cout << "The non-repeating elements are " << result[0] << " and " << result[1];
}