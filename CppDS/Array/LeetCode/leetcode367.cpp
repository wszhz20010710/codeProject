#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num){
        if(num==1)
        {
            return true;
        }
        int left = 1;
        int right = num/2;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (middle > num/middle)
            {
                right = middle - 1;
            }
            else if (middle < num/middle)
            {
                left = middle + 1;
            }
            else
            {
                return true;
            }
            
            
        }
        return false;
        
    }
};
