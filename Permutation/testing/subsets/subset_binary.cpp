#include <iostream>
#include <array>
#include <vector>
#include <cmath>

using namespace std;


void subsetBinary (vector<vector<int>> &perm_vec, array<int, 7> &arr) {
    
    for(int i = 0, f_l_e  = 1 << arr.size(); i < f_l_e; ++i) { // for loop end
        vector<int> push_vec; push_vec.reserve(arr.size());

        for (int sh = 0; sh < arr.size(); sh++) { // shift
            if (i & (1 << sh)) // if not equal to 0
                push_vec.push_back(arr[sh]);
        }
        

        perm_vec.push_back(push_vec);
    }
}


int main () {
    array<int, 7> arr{1, 2, 3, 4, 5, 6, 7};
    vector<vector<int>> perm_vec; perm_vec.reserve(pow(2, arr.size())); // permutation vector

    subsetBinary(perm_vec, arr);

    for(auto &vec: perm_vec) {
        for (auto &l : vec) cout << l << ", ";
        cout << endl;
    }
}