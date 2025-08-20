class Solution {
public:
    int countAsterisks(string s) {
        bool i_p = false; // inside_pair
        int n = 0;

        for(char l : s) {
            if (l == '|') i_p = !i_p;
            else if(!i_p && l == '*') n++;
        }

        return n;
    }
};