#include <iostream>
#include <array>
#include <vector>
#include <cmath>

using namespace std;

#define SIZE 4


void permutation(vector<vector<int>> &return_vec, array<int, SIZE> &arr, vector<int> &temp_vec, int i = 0) {
    if(i == arr.size()) {return_vec.push_back(temp_vec); return;}

    for (auto elem : arr) {
        temp_vec.push_back(elem);
        permutation(return_vec, arr, temp_vec, i+1);
        temp_vec.pop_back();
    }
}


int main () {
    array<int, 7> arr{1, 2, 3, 4};

    int j;
    for (int i = 1; i <= arr.size(); ++i) j *= i;
    vector<vector<int>> return_vec; return_vec.reserve(j);

    vector<int> temp_vec;

    permutation(return_vec, arr, temp_vec);

    for(auto &vec: return_vec) {
        for (auto &l : vec) cout << l << ", ";
        cout << endl;
    }
}