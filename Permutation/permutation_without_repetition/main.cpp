#include <vector>
#include <utility>
#include <iostream>

using namespace std;


// Function to find the possible permutations, Initial value of idx is 0
void permutations(vector<vector<int>>& res, vector<int>& arr, const int idx) {
    // Base case: if idx reaches the size of the array, add the permutation to the result
    // if (idx == arr.size()) { res.push_back(arr); return;}
    if (idx == arr.size() - 1) {
        res.push_back(arr);
        return;
    }

    // Permutations made by swapping each element, starting from index `idx`
    for (int i = idx; i < arr.size(); ++i) {
        swap(arr[idx], arr[i]);          // Swapping
        permutations(res, arr, idx + 1); // Recursive call to create permutations for the next element       
        swap(arr[idx], arr[i]);          // Backtracking, required to return the array back to how it was before, essential as we are passing by reference instead of copying
    }
}


// Wrapper function to call recursive permutations function
vector<vector<int>> permute(vector<int>& arr) {
    // Declaring result variable
    vector<vector<int>> res;
    // Calling permutations with idx starting at 0
    permutations(res, arr, 0);

    return res;
}


int main() {
    vector<int> arr = { 1, 2, 3, 4};
    vector<vector<int>> results = permute(arr);

    for (auto x : results) {
        for (auto y : x) cout << y << " ";
        cout << endl;
    }
}