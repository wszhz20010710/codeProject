// 使用哨兵字符作为停止标记
#include <iostream>
using namespace std;

int main()
{
    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin.get(ch);
    // 使用get()计算所有字符数量
    while (ch != '#') // 哨兵字符为 # 号
    {
        cout << ch;
        ++ count;
        cin.get(ch);
    }
    cout << endl << count << " characters read\n";
    return 0;
}