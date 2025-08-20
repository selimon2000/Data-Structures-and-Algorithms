#include <bits/stdc++.h>

using namespace std;


// Function to find all permutation of string
vector<string> findPermutation(string &s){

    // sort the string s
    sort(s.begin(), s.end());

    // stores all unique permutation
    vector<string> ans;

    // iterate until the next permutation exist
    do {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));


    return ans;
}


int main() {
    string s = "aabc";
    vector<string> ans = findPermutation(s);
    for(auto perm: ans) cout << perm << '\n';
    return 0;
}