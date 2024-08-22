// 一维数组 五只小猪称体重
#include <iostream>

using namespace std;

int main()
{
    int weight[] = {300, 350, 200, 400, 250, 50, 60, 11};
    int length = sizeof(weight) / sizeof(weight[0]);

    int min = weight[0];
    for (int i = 0; i < length; i++)
    {
        if (weight[i] < min)
        {
            min = weight[i];
        }
        else
            continue;
        
    }
    cout << min;
    return 0;
    
}