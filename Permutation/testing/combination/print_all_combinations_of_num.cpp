#include <vector>
#include <iostream>

using namespace std;


void printPermutation(const vector<vector<int>> &arr, const int k) {
    for (const auto &vec : arr) {
        for (auto elem : vec) cout << elem << ", ";
    cout << '\n';
    }
}


void makeCombiUtil(vector<vector<int>> &ans, vector<int> &tmp, int n, int left, int k) {
    // Pushing this vector to a vector of vector
    if (k == 0) {
        ans.push_back(tmp);
        return;
    }
    // i iterates from left to n. First time left will be 1
    for (int i = left; i <= n; ++i) {
        tmp.push_back(i);
        makeCombiUtil(ans, tmp, n, i + 1, k - 1);
        tmp.pop_back();
    }
}


// Prints all combinations of size k of numbers from 1 to n.
vector<vector<int>> makeCombination(int n, int k) {
    vector<vector<int>> ans;
    vector<int> tmp;
    makeCombiUtil(ans, tmp, n, 1, k);
    return ans;
}


int main() {
    int n = 5;
    int k = 3;
    vector<vector<int>> ans = makeCombination(n, k);
    
    printPermutation(ans, k);
}