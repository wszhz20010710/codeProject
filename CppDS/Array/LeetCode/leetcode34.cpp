#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int length = nums.size();
        if (length == 0)
        {
            return ans;
        }
        int left = 0, right = length-1;
        while (left < right)
        {
            int middle = 0.5 * (left + right);
            if (nums[middle] >= target)
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        if (nums[left] != target)
        {
            return ans;
        }
        else
        {
            ans[0] = left;
            left = 0;
            right = length - 1;
            while (left < right)
            {
                int middle = 0.5 * (left + right);
                if (nums[middle] <= target)
                {
                    left = middle;
                }
                else
                {
                    right = middle - 1;
                }
            }
            ans[1] = left;
        }
        return ans;
  
    }
};