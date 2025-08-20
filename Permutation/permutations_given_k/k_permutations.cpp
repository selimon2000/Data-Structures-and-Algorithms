#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Helper function to print the current permutation
void printPermutation(const vector<int> &arr, int k) {
    for (int i = 0; i < k; ++i) cout << arr[i] << " ";
    cout << '\n';
}


// Main recursive function to generate permutations
void generateUniqueKPermutations(vector<int> &arr, int k, int position) {
    // Base case: if we've placed k elements, print the permutation
    if (position == k) { printPermutation(arr, k); return; }

    // Used to track which values we've tried at this position
    vector<bool> used(10, false); // Assuming numbers are 0-9 for simplicity

    for (int i = position; i < arr.size(); i++) {
        // Skip if we've already used this number at this position
        if (used[arr[i]]) continue;

        // Mark this number as used at this position
        used[arr[i]] = true;

        // Swap current element with the position we're filling
        swap(arr[position], arr[i]);

        // Recursively generate permutations for remaining positions
        generateUniqueKPermutations(arr, k, position + 1);

        // Backtrack by swapping back
        swap(arr[position], arr[i]);
    }
}


// Public interface to generate permutations
void generate(vector<int> &arr, int k) {
    if (k > arr.size()) { cout << "k cannot be larger than array size\n"; return; }

    cout << "All unique " << k << "-permutations of the array:\n";
    generateUniqueKPermutations(arr, k, 0);
}


int main() {
    vector<int> arr = {1, 2, 9, 3};
    int k = 4; // Generate permutations of length 2
    generate(arr, k);
}