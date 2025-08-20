#include <iostream>
#include <vector>

using namespace std;


void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]) {
    if(ds.size() == nums.size()) { ans.push_back(ds);  return; }

    for(int i = 0; i < nums.size(); ++i) {
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
    int freq[nums.size()] = {};  
    recurPermute(ds, nums, ans, freq); 
    
    return ans; 
}


int main() {
    vector<int> nums = {1, 2, 3};  // Example input
    vector<vector<int>> permutations = permute(nums);

    cout << "Permutations:\n";
    for (const auto& perm : permutations) {
        for (int num : perm) cout << num << " ";
        cout << "\n";
    }
}