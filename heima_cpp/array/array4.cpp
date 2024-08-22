// 二维数组成绩统计
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // 载入数据
    string name[3] = {"张三","李四","王五"};
    int scores[3][3] = 
    {
        {100, 100, 100},
        {90, 50, 100},
        {60, 70, 80},
    };

    // 求和
    int total[3] = {0,0,0};
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            total[i] += scores[i][j];
        }
        
    }

    // 打印输出
    for (size_t i = 0; i < 3; i++)
    {
        cout << name[i] << "的总分为：" << total[i] << endl;
    }

    system("pause");
    return 0;
    
    
}