#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


// Helper function to print the current permutation
void printPermutation(const vector<int> &arr, const int k) {
    for (int i = 0; i < k; ++i) cout << arr[i] << " ";
    cout << '\n';
}


// Main recursive function to generate permutations
void generateUniqueKPermutations(vector<int> &arr, const int k, const int position) {
    if (position == k) { printPermutation(arr, k); return; }

    unordered_set<int> used; // Track used values at this depth level

    for (int i = position; i < arr.size(); ++i) {
        used.insert(arr[i]);

        swap(arr[position], arr[i]);                       // Swap current element with the position we're filling
        generateUniqueKPermutations(arr, k, position + 1); // Recurse
        swap(arr[position], arr[i]);                       // Backtrack
    }
}


int main() {
    vector<int> arr = {1, 2, 5, 3};
    int k = 2;

    generateUniqueKPermutations(arr, k, 0);
}