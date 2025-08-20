class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        uint8_t x = 0;
        for(char s : stones) {
            for (char j : jewels)
                if (s == j) x++;
        }

        return x;
    }
};