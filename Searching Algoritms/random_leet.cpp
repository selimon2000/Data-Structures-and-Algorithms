#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        uint32_t    l = 0,
                    r = nums.size() - 1;

        while (l <= r) {
            
            int m = (l + r) / 2;

            if(nums[m] == t)        return m;
            else if (t > nums[m])   l = m + 1;
            else                    r = m - 1;
        }


        return l;
    }
};