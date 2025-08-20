// Find Words Containing Character
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> return_vector;
        int n = words.size();
        
        for(int i = 0; i < n; i++) {
            for(auto letter:words.at(i))
                if(letter == x) {
                    return_vector.push_back(i);
                    break;
                }
        }

        return return_vector;
    }
};