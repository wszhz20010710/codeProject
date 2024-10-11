#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        int slowPtr = 0;
        for (int fastPtr = 1; fastPtr < nums.size(); fastPtr++)
        {
            if (nums[fastPtr] != nums[slowPtr])
            {
                nums[slowPtr+1] = nums[fastPtr];
                slowPtr++;
            }
            
        }
        return slowPtr+1;
        
    }
};