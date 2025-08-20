#include <iostream>
#include <array>
#include <vector>
#include <cmath>

using namespace std;


void subsetBinary (vector<vector<int>> &perm_vec, array<int, 7> &arr, vector<int> &input, int i = 0) {
    if(i == arr.size()) {perm_vec.push_back(input); return;}

    input.push_back(arr[i]);
    subsetBinary(perm_vec, arr, input, i+1);
    input.pop_back();
    subsetBinary(perm_vec, arr, input, i+1);
}


int main () {
    array<int, 7> arr{1, 2, 3, 4, 5, 6, 7};
    vector<vector<int>> perm_vec; perm_vec.reserve(pow(2, arr.size())); // permutation vector
    vector<int> input; input.reserve(7);
    subsetBinary(perm_vec, arr, input);

    for(auto &vec: perm_vec) {
        for (auto &l : vec) cout << l << ", ";
        cout << endl;
    }
}