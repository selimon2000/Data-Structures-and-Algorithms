class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int8_t x = 0;

        for(string op : operations) {
            if (op == "X++" | op == "++X") x++;
            else if (op == "X--" | op == "--X") x--;
        }

        return x;
    }
};