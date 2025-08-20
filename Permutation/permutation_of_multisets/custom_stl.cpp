#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void nextPermutation(string &input) {

    int n = input.size(); // Size of the given array
    int i = n - 2; // Start from the second last element

    // Find the first element that is not in a non-increasing sequence from the end
    while (i >= 0 && input[i] >= input[i + 1])
        --i;

    if (i >= 0) { // If such an element is found
    
        // Find the smallest element greater than input[i] to the right of it
        for (int j = n - 1; j > i; --j) {
            if (input[j] > input[i]) {
                swap(input[i], input[j]); // Swap them
                break;
            }
        }
    }

    // Reverse the sequence from input[i + 1] to the end of the array. This is to get the smallest possible permutation after i
    reverse(input.begin() + i + 1, input.end());
}


int main() {
    string s = "abcd";
    nextPermutation(s);
    cout << s << '\n';
}