// 二分查找
#include<iostream>

using namespace std;

int biSearch(int arr[], int target,int length)
{
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (arr[middle] < target)
        {
            left = middle + 1;
        }
        else if (arr[middle] > target)
        {
            right = middle - 1;
        }
        else
        {
            return middle;
        } 
    }
    return -1;
    
}

void test()
{
    int nums[] = {-1,0,3,5,9,12};
    int target = 5;
    int length = 6;
    cout << biSearch(nums, target, length) << endl;
}

int main()
{
    test();
    
    system("pause");
    return 0;
}
