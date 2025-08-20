#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define NO_OF_CHARS 256

// int lengthOfLongestSubstring(string s) {
//     int i = 0, j = 0, ans = 0;
//     map<char, int> m; // Map to track characters in the current window

//     while (j < s.size()) {
//         cout << "i:" << i << "\tj:" << j << endl;

//         m[s[j]]++; // Add current character to the map
//         int windowSize = j - i + 1; // Calculate the current window size

//         if (m.size() == windowSize) {
//             ans = max(ans, windowSize); // Update the maximum length of the substring
//             j++; // Expand the window by moving the end pointer
//         }
//         else {
//             while (m.size() < windowSize) {
//                 m[s[i]]--; // Remove characters from the start of the window
//                 if (m[s[i]] == 0)
//                     m.erase(s[i]);
//                 i++; // Move the start pointer to adjust the window
//                 windowSize = j - i + 1; // Update the window size
//             }
//             // Essential to have j++ to prevent an infinite loop, an optimise performance
//             j++;
//         }
//     }

//     return ans; // Return the length of the longest substring
// }


int lengthOfLongestSubstring(string str)
{
    // last index of all characters is initialized as -1
    vector<int> lastIndex(NO_OF_CHARS, -1);

    int res = 0;    
    int n = str.size();
    // Move end of current window
    for (int i = 0, j = 0; j < n; j++) {
        cout << "i: " << i << "\tj:" << j << endl;
        // Find the last index of str[j]
        // Update i (starting index of current window) as maximum of current value of i and last index plus 1
        // Basically, once it goes somewhere where it already exists, i iterates
        i = max(i, lastIndex[str[j]] + 1);
 
        // Update result if we get a larger window
        res = max(res, j - i + 1);
 
        // Update last index of j.
        lastIndex[str[j]] = j;
    }
    return res;
}
 


void test(string s) {
    cout << lengthOfLongestSubstring(s) << endl;
}


int main() {
    cout << "Length of longest substring with non-repeating characters: " << endl;
    // Test cases
    test("abac");          // Expected output: 4
    // test("abcdaef");        // Expected output: 6
    // test("abcabcbb");       // Expected output: 3 ("abc")
    // test("bbbbb");          // Expected output: 1 ("b")
    // test("pwwkew");         // Expected output: 3 ("wke")
    // test("");               // Expected output: 0 (Empty string)
    // test(" ");              // Expected output: 1 (" ")
    // test("abcdefg");        // Expected output: 7 ("abcdefg")
    // test("aabbccddeeff");   // Expected output: 2 ("aa" or "bb" or "cc" ...)
}