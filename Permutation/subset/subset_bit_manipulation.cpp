#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> subsets(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> res;

    // Loop through all possible subsets using bit manipulation
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> subset;

        // Loop through all elements of the input array
        for (int j = 0; j < n; ++j) {
            // Check if the jth bit is set in the current subset, if the jth bit is set, add the jth element to the subset
            if ((i & (1 << j)) != 0) subset.push_back(arr[j]);
        }

        // Push the subset into result
        res.push_back(subset);
    }


    return res;
}


int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> res = subsets(arr);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) cout << res[i][j] << " ";
        cout << endl;
    }
}