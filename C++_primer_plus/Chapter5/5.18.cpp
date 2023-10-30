// 检测文件尾 EOF 技术
#include <iostream>
using namespace std;

int main()
{
    char ch;
    int count = 0;
    cin.get(ch);
    // 使用get()计算所有字符数量
    while (cin.fail() == false) // 使用 Ctrl+Z+ENTER 作为结束标志
    {
        // cout << ch;
        ++ count;
        cin.get(ch);
    }
    cout << endl << count << " characters read\n";
    return 0;
}