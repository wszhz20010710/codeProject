#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x/2;
        while (left <= right)
        {
            int middle = left + right >> 1;
            if (middle > x/middle)
            {
                right = middle - 1;
            }
            else if (middle < x/middle)
            {
                left = middle + 1;
            }
            else
            {
                left = middle;
            }
            
        }
        return left;
        
        

    }
};