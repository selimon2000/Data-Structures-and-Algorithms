#include <iostream>
#include <string>

using namespace std;


void printPermutations(string str, string& permutations, int index) {
    if (index == permutations.size()) { cout << permutations << "\n"; return;}

    for (const char ch : str) {
        permutations[index] = ch;
        printPermutations(str, permutations, index + 1);
    }
}


int main() {
    const string str = "ABC";
    cout << "All permutations of the string with repetition of " << str << " are: " << endl;
    
    string permutations(str.size(), ' '); // Initialize with spaces
    printPermutations(str, permutations, 0);
}
