#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


// The main function that recursively prints all repeated permutations of the given string
void allLexicographicRecur(const string &str, string &data, int index) {
    int len = str.length();

    // Base case: if we have filled all positions, print the permutation
    if (index == len) { cout << data << endl; return; }

    // One by one fix all characters at the given index and recur
    for (int i = 0; i < len; i++) {
        data[index] = str[i];
        allLexicographicRecur(str, data, index + 1);
    }
}


// This function sorts input string, allocates memory for data, and calls allLexicographicRecur()
void allLexicographic(string str) {
    // Sort the input string to ensure lexicographic order
    sort(str.begin(), str.end());

    // Create a temporary string to hold permutations
    string data(str.size(), ' ');

    // Generate all permutations
    allLexicographicRecur(str, data, 0);
}


int main() {
    string str = "ABC";
    cout << "All permutations with repetition of " << str << " are:\n";
    allLexicographic(str);
}