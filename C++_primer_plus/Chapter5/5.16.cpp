// 使用哨兵字符作为停止标记
// 未计算空格、换行、回车等符号
#include <iostream>
using namespace std;

int main()
{
    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;
    while (ch != '#') // 哨兵字符为 # 号
    {
        cout << ch;
        ++ count;
        cin >> ch;
    }
    cout << endl << count << " characters read\n";
    return 0;
}