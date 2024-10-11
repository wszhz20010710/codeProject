#include<iostream>
#include<vector>
using namespace std;
// 双指针法移除元素


class Solution
{
public:
    int deleteElement(vector<int>& num, int val)
    {
        int SlowPtr = 0;
        for (int FastPtr = 0; FastPtr < num.size(); FastPtr++)
        {
            if (num[FastPtr] != val)
            {
                num[SlowPtr] = num[FastPtr];
                SlowPtr++;
            }
            
        }
        return SlowPtr;
    }

};




int main()
{
    vector<int>num = {0,1,2,2,3,0,4,2};
    int val = 3;
    Solution s;
    int res = s.deleteElement(num, val);
    cout << "res = " << res << endl;
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << " ";
    }
    

    system("pause");
    return 0;
}