#include <string>
#include <deque>
#include <iostream>
#include <cstdint>

using namespace std;


class Solution {
public:
    string simplifyPath(string &path) {
        deque<char> s;

        for (auto l = path.cbegin(); l != path.cend(); ++l) {
            
            if (*l == '.') {
                uint16_t dot_n = 0;
                for (; (l + dot_n) != path.cend() && *(l + dot_n) == '.'; ++dot_n);

                if (*(l - 1) != '/') {
                    for (uint16_t i = 0; i < dot_n; ++i) s.push_back('.');
                    l += dot_n - 1; continue;
                }

                if ((l + dot_n) != path.cend()) {
                    if (*(l + dot_n) != '/') {
                        for (uint16_t i = 0; i < dot_n; ++i) s.push_back('.');
                        l += dot_n - 1; continue;
                    }
                }

                if (dot_n == 2) {
                    if (s.size() == 1) {l += 1; continue;}
                    s.pop_back(); // remove the '/'
                    while (!s.empty() && (s.back() != '/')) s.pop_back();
                }

                // if it's greater than 2:
                else if (dot_n > 2) 
                    for (uint16_t i = 0; i < dot_n; ++i) s.push_back('.');
                
                l += dot_n - 1;
                continue;
            }

            if (!s.empty()) {
                if (s.back() == '/') {
                    if (*l == '/')  continue;
                    else            s.push_back(*l);
                }
                else s.push_back(*l);
            }
            else s.push_back(*l);
        }
        
        
        if (s.size() != 1)
            if (s.back() == '/')
                s.pop_back();
                
        path.clear();
        path.reserve(s.size());
        for (auto it = s.cbegin(); it != s.cend(); ++it) path.push_back(*it);
        

        return path;
    }
};


int main () {
    Solution s;

    string input{"/home/user/Documents/../Pictures"s};

    cout << s.simplifyPath(input) << '\n';
}