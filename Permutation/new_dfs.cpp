#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]) {
    if(ds.size() == nums.size()) {
        ans.push_back(ds); 
        return; 
    }
    for(int i = 0;i<nums.size();i++) {
        if(!freq[i]) {
            ds.push_back(nums[i]);
            freq[i] = 1; 
            recurPermute(ds, nums, ans, freq);
            freq[i] = 0; 
            ds.pop_back(); 
        }
    }
    
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans; 
    vector<int> ds; 
    int freq[nums.size()]; 
    for(int i = 0;i<nums.size();i++) freq[i] = 0; 
    recurPermute(ds, nums, ans, freq); 
    return ans; 
}

int main() {
    vector<int> nums{1, 2, 3, 3};
    vector<vector<int>> p_vec = permute(nums);

    for (int i = 0; i < p_vec.size(); ++i) {
        for (int j = 0; j < p_vec[i].size(); ++j) cout << p_vec[i][j] << ", ";
        cout << endl;
    }
}