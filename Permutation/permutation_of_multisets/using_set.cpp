/*Function generates all possible permutations, and filters duplicates using hash set to the result array*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;


void genPermutation(int i, string &s, vector<bool> &used, string &curr, unordered_set<string> &st) {
   
    if (i == s.size()) {
        // Add the permutation to the result set
        st.insert(curr);
        return;
    }

    for (int j = 0; j < s.size(); j++) {
        if (!used[j]) {
            // Mark the character as used
            used[j] = true;
            curr.push_back(s[j]);

            // Recurse with the next character
            genPermutation(i + 1, s, used, curr, st);

            // Backtrack and unmark the character
            used[j] = false;
            curr.pop_back();
        }
    }
}


vector<string> findPermutation(string &s) {
    vector<bool> used(s.size(), false);
    unordered_set<string> st;

    string curr = "";

    // Start the recursion
    genPermutation(0, s, used, curr, st);

    // Convert the set to a vector
    vector<string> res(st.begin(), st.end());
    return res;
}


int main() {
    string s = "ABCC";
    vector<string> res = findPermutation(s);

    for (string perm : res) cout << perm << '\n';
}