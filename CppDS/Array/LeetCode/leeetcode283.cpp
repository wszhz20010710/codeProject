#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums){
        int slowPtr = 0;
        for (int fastPtr = 0; fastPtr < nums.size(); fastPtr++)
        {
            if (nums[fastPtr] != 0)
            {
                swap(nums[slowPtr], nums[fastPtr]);
                slowPtr++;
            }

            
            
        }
        

    }
};