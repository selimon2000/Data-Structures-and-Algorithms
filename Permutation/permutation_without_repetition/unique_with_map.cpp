/* Generating Only Unique Permutations of string using hash map*/

/* Input: Uses Frequency Map */

/* Duplicate permutations are generated in the previous approach because it treats identical characters,
like the two ‘B’s in “ABBC,” as distinct due to their indices. For example, when placing a ‘B’ at an
index, choosing the first or second ‘B’ results in the same permutation (e.g., “ABBC” or “ABBC” again),
leading to duplicates.

In this approach, we prune branches in the recursive tree that would generate duplicate permutations and
place only unique available characters at each index.*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


// Recursive function to generate permutations
void genPermutations(int n, string &curr, unordered_map<char, int> &cnt, vector<string> &res) {

    // Base case: If the current permutation length equals the input string length, add it to the result
    if (curr.size() == n) {
        res.push_back(curr);
        return;
    }

    // Iterate through each character in the frequency map
    for (pair<char, int> it : cnt) {
        char c = it.first;
        int count = it.second;

        // Skip characters with a count of 0
        if (count == 0) continue;

        // Include the character in the current permutation
        curr.push_back(c);

        // Decrease its count in the frequency map
        cnt[c]--;

        // Recur to build the next character in the permutation
        genPermutations(n, curr, cnt, res);

        // Backtrack: Remove the character and restore its count
        curr.pop_back();
        cnt[c]++;
    }
}


vector<string> findPermutation(string s) {

    // Vector to store the result
    vector<string> res;

    // Frequency map to count occurrences of each character
    unordered_map<char, int> cnt; for (char c : s) cnt[c]++;

    // Build permutations
    string curr = "";
    genPermutations(s.size(), curr, cnt, res);
    return res;
}


int main() {
    string s = "ABCC";
    vector<string> res = findPermutation(s);

    for (string perm : res) cout << perm << "\n";
}