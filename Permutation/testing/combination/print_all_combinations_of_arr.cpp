#include <iostream>
#include <vector>

using namespace std;


void printArr(vector<vector<int>> &result) {
    for (const auto& combination : result) {
        for (int element : combination) cout << element << " ";
        cout << "\n";
    }
}


void generateCombinations(vector<vector<int>>& result, vector<int>& current, const vector<int>& arr, int k, int start) {
    // Base case: if the current combination is of size k, add it to the result
    if (current.size() == k) {
        result.push_back(current);
        return;
    }

    // Recursive case: include each element one by one
    for (int i = start; i < arr.size(); ++i) {
        current.push_back(arr[i]); // Include the current element
        generateCombinations(result, current, arr, k, i + 1); // Recur with the next index
        current.pop_back(); // Exclude the current element (backtrack)
    }
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; // Input array
    int k = 5; // Size of combinations
    vector<vector<int>> result; // To store all combinations
    vector<int> current; // To store the current combination

    generateCombinations(result, current, arr, k, 0);
    printArr(result);
}