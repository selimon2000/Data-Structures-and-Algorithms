#include <iostream>
#include <array>
#include <vector>
#include <set>

using namespace std;


void printArray(const vector<int>& arr) {
    for (const auto& element : arr) cout << element << " ";
    cout << '\n';
}


void heapPermutation(vector<int>& arr, set<vector<int>> &permutation_set, const int idx) {
    // Base case: if idx is 1, we've reached a permutation
    if (idx == 1) { 
        if (permutation_set.find(arr) == permutation_set.end()){
            permutation_set.insert(arr);
            printArray(arr);
        }
        return;
    }
    
    // Generate permutations for each element as the last element
    for (int i = 0; i < idx; ++i) {
        // Recursively generate permutations with idx-1
        heapPermutation(arr, permutation_set, idx - 1);
        
        // If idx is odd (REMEMBER idx, NOT i), swap first and last element in the subarray
        // If idx is even, swap current and last element in the subarray
        swap(arr[  (idx & 1) ? 0 : i  ], arr[idx - 1]);
    }
}


int main() {
    // Initialize the array with values
    vector<int> arr = {1, 2, 3, 3};

    // Generate and print all permutations
    cout << "All permutations of the array:\n";
    set<vector<int>> permutation_set;
    heapPermutation(arr, permutation_set, arr.size());
}